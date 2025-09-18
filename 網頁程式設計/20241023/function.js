function addBorder() {
    document.getElementById('lenna').style.border = '10px solid';
}
function changeColor() {
    document.getElementById('change_color').style = 'Color:blue';
}
function changeTableColor(color){
    let elements = document.querySelectorAll('#table td');
    elements.forEach(cell=>{
        cell.style.backgroundColor = color
    })
}
function changeTableBlue(){
    document.getElementsByClassName('a').style.backgroundColor = 'blue';
}
function changeTablePurple(){
    document.getElementsByClassName('a').style.backgroundColor = 'purple';
}
function changeTableOrange(){
    document.getElementsByClassName('a').style.backgroundColor = 'orange';
}
function changeTableWidth200(){
    document.getElementById('table').style.width = '200px';
}
function changeTableWidth500(){
    document.getElementById('table').style.width = '500px';
}
function changeTableBorderSpacing(value){
    document.getElementById('table').style.borderSpacing = value;
    document.getElementById('table').style.border = value+" solid black";
}
function reset(){
    changeTableColor('rgb(253, 253, 113)');
    changeTableWidth200();
    changeTableBorderSpacing('1px');
}