#include <bits/stdc++.h> 
#include <JavaScriptCore/JavaScript.h>
#include "utilityFunctions.cpp"
#include "LedgerGenerator.cpp"

using namespace std;


void setLedgerTable(JSContextRef ctx){
    LedgerGenerator lg;
    list<string> all_ledger_data = lg.getLedgerData();  
    string javascript_data_array = "["; //start;
    
    for(auto x : all_ledger_data){
        javascript_data_array = javascript_data_array + "\""+ x + "\"" + ",";
    }

    if(all_ledger_data.size()>0)
        javascript_data_array = javascript_data_array.substr(0, javascript_data_array.size()-1); //remove last ","
    
    javascript_data_array = javascript_data_array + "]" ; //end
    string to_set_table = "setTable('"+javascript_data_array+"');";
    cout<<to_set_table<<endl;
    cout.flush();
    modifyHTML(ctx,to_set_table.c_str());
}

JSValueRef genLedger(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, 
                        const JSValueRef arguments[], JSValueRef* exception){
    LedgerGenerator lg;
    lg.generateLedger();
    setLedgerTable(ctx);
    return JSValueMakeNull(ctx);
}   