var fs = require('fs');

fs.readFile('New Document 3.tldr.json', 'utf8', function (err, data) {
  if (err) {
    console.log(err);
  } else {
    myarray = JSON.parse(data);
	// console.log(JSON.parse(data));
	// console.log(myarray.document.pages.page.shapes);
	// console.log(Object.keys(myarray.document.pages.page.shapes));
	var id = "424288da-6aed-4f89-16a2-ccdbb747cb9d"
	const result = myarray.document.pages.page.shapes.id;
	console.log(result)
	// let data1 = result;
	// var list = {};
	// for(let key in result)
	// {	// console.log(key);
	// 	// console.log(result[key]);
	// 	data1 = result[key];
	// 	break;
	// }
	// for (let x in data1.points)
	// {
	// 	console.log(data1.points[x]);
	// }
}
});