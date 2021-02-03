#!/usr/bin/node
const process = require('process');
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request.get(url, function (err, response, body) {
  if (err) {
    return console.log(err);
  }
  const list = JSON.parse(body).characters;
  for (let i = 0; i < list.length; i++) {
    request.get(list[i], function (errList, responseList, bodyList) {
      if (errList) {
        return console.log(errList);
      }
      return console.log(JSON.parse(bodyList).name);
    });
  }
});
