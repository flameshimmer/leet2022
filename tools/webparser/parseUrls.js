'use strict';
const puppeteer = require('puppeteer');
const fs = require('fs');


processPage();

async function processPage() {
    for (var i = 1; i<=21; i++) {
        GetItemLink('https://leetcode.com/problemset/algorithms/?sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=' + i, i);    
    }
}

async function GetItemLink(url, pageIndex) {
    console.log("Processing :" + url);
    let scrape = async () => {
        const wsChromeEndpointurl = 'ws://127.0.0.1:9222/devtools/browser/4cd14ec9-3e8a-4850-a6c8-7068d9f39370';
        var browser = await puppeteer.connect({
            browserWSEndpoint: wsChromeEndpointurl,
            headless: true,
        });            
        const page = await browser.newPage();
        await page.setDefaultNavigationTimeout(120000); 

        await page.goto(url);
        //await page.waitForNavigation({waitUntil: 'networkidle2'})
        await page.waitFor(20000);
        const result = await page.evaluate(() => {
            let data = []; // Create an empty array that will store our data
            let listItems = document.querySelectorAll('a.h-5'); // Select all Products
            for (var anchorElem of listItems){ // Loop through each proudct
                // let anchorElem = document.querySelector('a'); // Select all Products  
                let title = anchorElem.innerText; // Select the title
                let src = anchorElem.href; // Select the price
                data.push({title, src}); // Push an object with the data onto our array
            }
 
            return data; // Return our data array
        });

        // browser.close();
        return result; // Return the data
    };

    let data = await scrape();
    console.log("size of data is:" + data.length);  
    let dataFlat = JSON.stringify(data) + "\n"; 

    fs.writeFileSync('problemIndex/mostFrequent_page_' + pageIndex, dataFlat);
    console.log(dataFlat); // Success!
    return dataFlat;
}
