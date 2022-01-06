const express = require("express")
const app = express()
const fs = require('fs')
const url = require('url')
const port = 9001

//Expose necessary directories 
app.use('/images', express.static(__dirname + '/images'));
app.use('/public', express.static(__dirname + '/public'));
app.use('/secret-page', express.static(__dirname + '/secret-page'));

//Redirect base to index.html with GET param
app.get('/', function(req, res) { 
    res.status(302).redirect("/index.html?image=robot-1"); 
})

//Serve request based on GET params
app.get("/index.html", (req,res) => {
    res.writeHead(200, { "Content-Type": "text/html" })
    fs.readFile("index.html", function(error, data) {
        const params = url.parse(req.url, true).query;

        if (error) {
            res.writeHead(404)
            res.write("File not found!")
        } else { //standard responses
            if (['robot-1', 'robot-2', 'robot-3'].includes(params.image)) {
                res.write(data)
            } else if (params.image == 'flag' && params.authorized == 'yes') { // pay the prize
                res.write(data)
            } else {
                res.write("Unauthorized or unknown!")
            }
        }
        res.end()
    })
})

app.listen(port, function(error) {
    if (error) {
        console.log("[!] Something went wrong", error)
    } else {
        console.log(`[!] Server is listening on port ${port}`)
    }
})