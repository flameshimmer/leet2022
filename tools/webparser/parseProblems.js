'use strict';
const puppeteer = require('puppeteer');
const fs = require('fs');
require('events').EventEmitter.defaultMaxListeners = 500;

let unfinishedFileName = 'problems/unfinished';

//processPage('allProblemUrls');
processUnfinished();


async function processPage(urlFileName) {
    let allUrls = fs.readFileSync(urlFileName) + '';
    var urls = allUrls.split("\n");

    // fs.writeFileSync('problems/unfinished', '');
    // var tasks = [];
 //    for (var i = 842; i<urls.length; i++) {
 //        var url = urls[i];
 //        tasks.push([url, 'mostFrequent_'+i, false]);
 //    } 
	// const asyncBatch = require('async-batch').default;
 //    await asyncBatch(tasks, GetItemLink, 3);	
     for (var i = 2091; i<urls.length; i++) {
        var url = urls[i];
        await GetItemLink([url, 'mostFrequent_'+i, false]);
    } 
}

async function processUnfinished() {
    let unfinished = (fs.readFileSync(unfinishedFileName).toString()).split("\r");
    console.log(unfinished.length);
    
    // var tasks = [];
    // for (var i = 0; i<unfinished.length; i++) {
    //     var info = unfinished[i].split(",");
    //     var name = info[0];
    //     var url = info[1];
    //     tasks.push([url, name, true]);
    // } 
    // const asyncBatch = require('async-batch').default;
    // await asyncBatch(tasks, GetItemLink, 3);
     for (var i = 0; i<unfinished.length; i++) {
        var info = unfinished[i].split(",");
        var name = info[0];
        var url = info[1];
        try {
            await GetItemLink([url, name, true]);
        } catch(e) {
            // Did you forget to update teh wsChromeEndpoint???
            console.log(e);
            return;
        }
    }     
}


async function GetItemLink(task) {
	var url = task[0];
	var name = task[1];
    var connectWithChromeSession = task[2];

	console.log("Processing task: " + name + ", connect: " + connectWithChromeSession + ", url: " + url);
	if (isEmptyOrSpaces(url)) {return;}

    let scrape = async () => {
       var browser = await puppeteer.launch({headless: true});
        if (connectWithChromeSession) {
            // Open in current browser: https://medium.com/@jaredpotter1/connecting-puppeteer-to-existing-chrome-window-8a10828149e0
            const wsChromeEndpointurl = 'ws://127.0.0.1:9222/devtools/browser/1b748e15-88f1-4d38-82ad-e1c465ab55bd';
            var browser = await puppeteer.connect({
                browserWSEndpoint: wsChromeEndpointurl,
                headless: false,
            });            
        }

        const page = await browser.newPage();
        await page.setDefaultNavigationTimeout(120000); 

        await page.goto(url);
        if (connectWithChromeSession){
            await page.waitForSelector('div.css-v3d350');
        }
        const result = await page.evaluate(() => {
            let data = {}; // Create an empty array that will store our data
            let title = document.querySelector('div.css-v3d350'); // Select all Products  
            let description = document.querySelector('div.content__u3I1'); // Select all Products  
            let functionSig = document.querySelector('div.CodeMirror-code'); // Select all Products  
                      
            if (title != null) {
            	data["title"] = title.innerText;	
            }
            if (description != null) {
            	data["description"] = description.innerText;	
            }
            if (functionSig != null) {
            	data["functionSig"] = functionSig.innerText;	
            }            
            return data; // Return our data array
        });

        if (!connectWithChromeSession) {
            browser.close();    
        }        
        return result; // Return the data
    };


    let data = JSON.stringify(await scrape());
    if (data == '{}') {
        if (!connectWithChromeSession) {
            fs.appendFileSync('problems/unfinished', name + ',' + url);
        } else {
            fs.appendFileSync('problems/unfinished_2', name + ',' + url);
        }
    }

    fs.writeFileSync('problems/data_' + name, data + "\n");
    console.log(data); // Success!
    return data;
}



function isEmptyOrSpaces(str){
    if (!str) {return true;}
    return str === null || str.match(/^ *$/) !== null;
}