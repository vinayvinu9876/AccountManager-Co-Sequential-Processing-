$("#close").click(function(){
    window.location.href = "./TransactionsManager.html";
})

function validDate(date){
    try{
        date = date.split('/');
        if(parseInt(date[0])>31 || parseInt(date[0])<1){
            showNotification("Date "+date[0]+" is not valid","Transaction Manager");
            return false;
        }
        else if(parseInt(date[1])>12 || parseInt(date[1])<12){
            showNotification("Month "+date[1]+" is not valid","Transaction Manager");
            return false;
        }
        else if(parseInt(date[2])<1950 || parseInt(date[2])>2020){
            showNotification("Year "+date[2]+" is not valid","Transaction Manager");
            return false;
        }
        return true;
    }   
    catch(err){
        showNotification(err.message,"Transaction Manager");
        return false;
    }
}

$("#addbutton").click(function(){
    var account_no = $("#account_no").val();
    var check_number = $("#check_number").val();
    var date = $("#date").val();
    var description = $("#description").val();
    var debit_credit = $("#debit_credit").val();

    if(!validDate(date)){
        showNotification("Date invalid","Transaction Manager");
        return;
    }

    addTransaction(account_no,check_number,date,description,debit_credit);
})

