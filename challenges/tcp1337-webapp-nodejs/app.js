const express = require("express")
const app = express()
const fs = require('fs')
const port = 1337

app.use('/images', express.static(__dirname + '/images'));

app.get("/", (req,res) => {
    res.writeHead(200, { "Content-Type": "text/html", "X-FLAG": "FBC{use_your_head_check_out_the_headers}" })
    fs.readFile("index.html", function(error, data) {
        if (error) {
            res.writeHead(404)
            res.write("File not found!")
        } else {
            res.write(data)
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