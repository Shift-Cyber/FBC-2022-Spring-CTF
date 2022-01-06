const fs = require('fs')
const express = require("express")
const jwt = require('jsonwebtoken')
const app = express()
const port = 9001

//Expose necessary directories 
app.use('/media', express.static(__dirname + '/media'));
app.use('/public', express.static(__dirname + '/public'));

//Use JSON for processing
app.use(express.json())

// Create token with a very long expiration
const token = jwt.sign(
{ user: "administrator", admin: "no" },
    "1488e16f60c15565ad989f924a99e3a0",
    {
        expiresIn: "1000d",
        issuer: "Fallbrook Cyber (FBC)",
    }
);
console.log(`JWT Initalized: ${token}\n`)

//Redirect base to index.html with GET param
app.get('/', function(req, res) { 
    res.status(302).redirect("/login.html"); 
})

//Serve request based on GET params
app.get("/login.html", (req,res) => {
    res.writeHead(200, { "Content-Type": "text/html" })
    fs.readFile("login.html", function(error, data) {
        if (error) {
            res.writeHead(404)
            res.write("File not found!")
        } else { //standard responses
            res.write(data)
        }
        res.end()
    })
})
app.get("/admin.html", (req,res) => {
    recv_token = req.headers.authorization.split(' ').pop();
    recv_token_decoded = jwt.decode(recv_token) // notice this is decoded and not signed

    if (recv_token_decoded.user === "administrator" && recv_token_decoded.admin === "yes") {
        // token forged, pay the prize
        res.writeHead(200)
        res.write("FBC{gimme_that_real_john_hancock}")
        res.send()
    } else { // invalid token
        res.writeHead(401).send()
    }
    res.end()
})

app.post("/login.html", (req,res) => {
    // Validate credentials
    if (req.body.username === "admin" && req.body.password === "monkeybusiness") {
        res.header({ "Authorization": "Bearer " + token, "X-FLAG": "FBC{ill_get_to_it_when_i_get_to_it}" })
        res.redirect(202, "/admin.html"); 
    } else { //bad creds
        res.writeHead(401).send()
    }
    res.end()
})

app.listen(port, function(error) {
    if (error) {
        console.log("[!] Something went wrong", error)
    } else {
        console.log(`[!] Server is listening on port ${port}`)
    }
})