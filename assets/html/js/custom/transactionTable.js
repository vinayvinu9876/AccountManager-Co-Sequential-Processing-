$("#addtransaction").click(function(){
    window.location.href = "./addTransaction.html";
})

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

function getTableHeader(){
    return `<thead>
                <tr>
                    <th>#</th>
                    <th>Account No</th>
                    <th>Check Number</th>
                    <th>Date</th>
                    <th>Description</th>
                    <th>Debit/Credit</th>
                    <th>Delete</th>
                </tr>
            </thead>`;
}

function getDeleteButton(id){
    return "<button class='btn btn-danger' style='height:30px' onclick='deleteTransaction(\""+id+"\")'>Delete</button>";
}

function getRow(arr){
    var tablerow = "<tr>";
    arr.forEach(function(elem){
        tablerow  = tablerow + "<td>"+elem+"</td>";
    });
    tablerow = tablerow + "<td>"+getDeleteButton(arr[0])+"</td>";
    tablerow = tablerow + "</tr>";
    return tablerow;
}

function setTable(string_data_array){
    var data_array = JSON.parse(string_data_array);
    if(data_array.length===0){
        $("#content-space").html("<div class='m-4'><center><h1>No Record Found</h1></center></div>");
        return;
    } 
    var table_content = "<table class='table'>"+getTableHeader();
    data_array.forEach(function(line){
        var arr = line.split("|");
        table_content = table_content + getRow(arr);
    });
    table_content = table_content + "</table>";
    $("#content-space").html(table_content);
    
    //$("body").html(string_data_array);
}
  
function getRecordData(){
    try{
        getTransaction(); 
    }
    catch(err){
        document.body.innerHTML = err.message;
    }
}

$(document).ready(function(){
    sleep(1000).then(function(){
        getRecordData();
    })  
})