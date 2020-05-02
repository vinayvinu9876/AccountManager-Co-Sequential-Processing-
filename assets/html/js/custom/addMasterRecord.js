$("#addbutton").click(function(){
    var name = $("#name").val();
    var email = $("#email").val();
    var phone = $("#phone").val();
    addMasterRecord(name,phone,email);
})

$("#close").click(function(){
    window.location.href = "./MasterRecordManager.html";
})