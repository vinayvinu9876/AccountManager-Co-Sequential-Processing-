#include <bits/stdc++.h> 
#include <JavaScriptCore/JavaScript.h>
#include "utilityFunctions.cpp"
#include "convertJSStringToString.cpp"
#include "MasterRecordManager.cpp"

using namespace std;

void setTable(JSContextRef ctx){
    MasterRecordManager mrm;
    list<string> all_account_data = mrm.getAllAccountDetails();
    string javascript_data_array = "["; //start;
    
    for(auto x : all_account_data){
        javascript_data_array = javascript_data_array + "\""+ x + "\"" + ",";
    }

    if(all_account_data.size()>0)
        javascript_data_array = javascript_data_array.substr(0, javascript_data_array.size()-1); //remove last ","
    
    javascript_data_array = javascript_data_array + "]" ; //end
    string to_set_table = "setTable('"+javascript_data_array+"');";
    cout<<to_set_table<<endl;
    cout.flush();
    modifyHTML(ctx,to_set_table.c_str());
}


JSValueRef addMasterRecord(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, 
                        const JSValueRef arguments[], JSValueRef* exception){

    MasterRecordManager mrm;
    //Get Parameters
    string name = JSStringToStdString(JSValueToStringCopy(ctx,arguments[0],exception));
    string phone = JSStringToStdString(JSValueToStringCopy(ctx,arguments[1],exception));
    string email = JSStringToStdString(JSValueToStringCopy(ctx,arguments[2],exception));

    cout<<"Name = "<<name<<" Phone "<<phone<<" Email = "<<email<<endl;
    cout.flush();


    bool result = mrm.addAccount(name,phone,email);

    string message;
    if(result)
        message = "Account Created Succesfully";
    else
        message = "Account creation failed";


    string to_notify = "showNotification(' "+message+" ', 'MasterRecordManager')";
    modifyHTML(ctx,to_notify.c_str());
    //refresh items
    //setDBTable(dba,ctx);
    //create database  
    return JSValueMakeNull(ctx);
}

JSValueRef getMasterRecord(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, 
                        const JSValueRef arguments[], JSValueRef* exception){
    cout<<"I got called"<<endl;
    cout.flush();
    setTable(ctx);
    return JSValueMakeNull(ctx);

} 

JSValueRef deleteMasterRecord(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, 
                        const JSValueRef arguments[], JSValueRef* exception){
    MasterRecordManager mrm;
    //Get Parameters
    string account_no = JSStringToStdString(JSValueToStringCopy(ctx,arguments[0],exception));

    bool result = mrm.removeAccount(account_no);

    string message;
    if(result)
        message = "Account Deleted Succesfully";
    else
        message = "Account Deletion failed";


    setTable(ctx);
    string to_notify = "showNotification(' "+message+" ', 'MasterRecordManager')";
    modifyHTML(ctx,to_notify.c_str());


    return JSValueMakeNull(ctx);
}