$("#genledger").click(function(){
    genLedger();
})


function getTableHeader(){
    return `<thead>
                <tr>
                    <th>Account No</th>
                    <th>Name</th>
                    <th>Jan</th>
                    <th>Feb</th>
                    <th>Mar</th>
                    <th>Apr</th>
                    <th>May</th>
                    <th>Jun</th>
                    <th>Jul</th>
                    <th>Aug</th>
                    <th>Sep</th>
                    <th>Oct</th>
                    <th>Nov</th>
                    <th>Dec</th>
                </tr>
            </thead>`;
}


function getRow(arr){
    var tablerow = "<tr>";
    arr.forEach(function(elem){
        tablerow  = tablerow + "<td>"+elem+"</td>";
    });
    tablerow = tablerow + "</tr>";
    return tablerow;
}

function setTable(string_data_array){
    var data_array = JSON.parse(string_data_array);
    data_array.shift();
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
  

