const express = require("express")
const app = express()
const port = 3000

const users = [ {username: 'Name', password: 'Password'} ]

app.use(express.json())

app.get("/users", (req,res) => {
    res.json(users)
})

app.post("/users", (req,res) => {
    user = { username: req.body.username, password: req.body.password }
    users.push(user)
    res.status(201).send()
})

app.listen(port)