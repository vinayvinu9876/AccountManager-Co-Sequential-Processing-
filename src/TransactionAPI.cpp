#include <bits/stdc++.h> 
#include <JavaScriptCore/JavaScript.h>
#include "utilityFunctions.cpp"
#include "convertJSStringToString.cpp"
#include "TransactionManager.cpp"

using namespace std;

void setTransactionTable(JSContextRef ctx){
    TransactionManager tm;
    list<string> all_transaction_data = tm.getAllTxnDetails();  
    string javascript_data_array = "["; //start;
    
    for(auto x : all_transaction_data){
        javascript_data_array = javascript_data_array + "\""+ x + "\"" + ",";
    }

    if(all_transaction_data.size()>0)
        javascript_data_array = javascript_data_array.substr(0, javascript_data_array.size()-1); //remove last ","
    
    javascript_data_array = javascript_data_array + "]" ; //end
    string to_set_table = "setTable('"+javascript_data_array+"');";
    cout<<to_set_table<<endl;
    cout.flush();
    modifyHTML(ctx,to_set_table.c_str());
}

JSValueRef addTransaction(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, 
                        const JSValueRef arguments[], JSValueRef* exception){
    TransactionManager tm;

    string account_no = JSStringToStdString(JSValueToStringCopy(ctx,arguments[0],exception));
    string check_no = JSStringToStdString(JSValueToStringCopy(ctx,arguments[1],exception));
    string date = JSStringToStdString(JSValueToStringCopy(ctx,arguments[2],exception));
    string description = JSStringToStdString(JSValueToStringCopy(ctx,arguments[3],exception));
    string debit_credit = JSStringToStdString(JSValueToStringCopy(ctx,arguments[4],exception));

    bool result = tm.addTransaction(account_no,check_no,date,description,debit_credit);

    string message;
    
    if(result)
        message = "Transaction Succesfully";
    else
        message = "Transaction Failed";

    string to_notify = "showNotification( '"+message+"', 'Transaction Manager');";
    modifyHTML(ctx,to_notify.c_str());

    return JSValueMakeNull(ctx);
}


JSValueRef getTransaction(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, 
                        const JSValueRef arguments[], JSValueRef* exception){

    setTransactionTable(ctx);
    return JSValueMakeNull(ctx);
}

JSValueRef deleteTransaction(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, 
                        const JSValueRef arguments[], JSValueRef* exception){
        TransactionManager tm;
        string transaction_number = JSStringToStdString(JSValueToStringCopy(ctx,arguments[0],exception));
        bool result = tm.removeTransaction(transaction_number);

        string message;
    
        if(result)
            message = "Transaction Deleted Succesfully";
        else
            message = "Transaction Delete Failed";

        string to_notify = "showNotification( '"+message+"', 'Transaction Manager');";
        modifyHTML(ctx,to_notify.c_str());

        setTransactionTable(ctx);

        return JSValueMakeNull(ctx);
        
} 