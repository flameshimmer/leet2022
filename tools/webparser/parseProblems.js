'use strict';
const puppeteer = require('puppeteer');
const fs = require('fs');
require('events').EventEmitter.defaultMaxListeners = 500;

let unfinishedFileName = 'problems/unfinished';
// processPage('allProblemUrls');
 processUnfinished();

async function processUnfinished() {
    let unfinished = (fs.readFileSync(unfinishedFileName).toString()).split("\r");
    console.log(unfinished.length);
    //fs.writeFileSync(unfinishedFileName, '');
    
    var tasks = [];
    for (var i = 0; i<unfinished.length; i++) {
    	//console.log("!!!unfinished" + i +  ": " + unfinished[i]);
        var info = unfinished[i].split(",");
        var name = info[0];
        var url = info[1];
        tasks.push([url, name, true]);
    } 
	const asyncBatch = require('async-batch').default;
    await asyncBatch(tasks, GetItemLink, 3);
}


async function processPage(urlFileName) {
    let allUrls = fs.readFileSync(urlFileName) + '';
    var urls = allUrls.split("\n");

    fs.writeFileSync('problems/unfinished', '');
    var tasks = [];
    for (var i in urls) {
        var url = urls[i];
        tasks.push([url, 'mostFrequent_'+i, false]);
    } 
	const asyncBatch = require('async-batch').default;
    await asyncBatch(tasks, GetItemLink, 10);	
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
            const wsChromeEndpointurl = 'ws://127.0.0.1:9222/devtools/browser/1ed08d20-2e19-4f01-8b32-00f9408befc5';
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
    	fs.appendFileSync('problems/unfinished', name + ',' + url);
    }

    fs.writeFileSync('problems/data_' + name, data + "\n");
    console.log(data); // Success!
    return data;
}



function isEmptyOrSpaces(str){
    if (!str) {return true;}
    return str === null || str.match(/^ *$/) !== null;
}