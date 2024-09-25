var express = require("express");
var router = express.Router();

const items = [
  { id: 1, name: "Computer" },
  { id: 2, name: "Laptop" },
  { id: 3, name: "Mouse" },
  { id: 4, name: "Keyboard" },
  { id: 5, name: "Headphones" },
];

const baskets = {};

/* GET home page. */
router.get("/", function (req, res, next) {
  if(!baskets[req.cookies.session_id]) 
  {baskets[req.cookies.session_id] = [];}
  res.render("index", { items, 'basket': baskets[req.cookies.session_id]});
});

router.post("/addItem", function (req, res, next) {
  const { id } = req.body;
  const item = items.find((item) => item.id == id);
  
  if(!req.cookies.session_id)
  {
    req.cookies.session_id = Math.random().toString();
    baskets[req.cookies.session_id] = [];
  }

  baskets[req.cookies.session_id].push(item);
  res.cookie('basket', baskets[req.cookies.session_id]);
  res.cookie('session_id',req.cookies.session_id)
  res.redirect("/");
});

module.exports = router;
