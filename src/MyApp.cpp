#include "MyApp.h"

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 400

#include "MasterRecordAPI.cpp"
#include "TransactionAPI.cpp"
#include "LedgerAPI.cpp"

MyApp::MyApp() {
  ///
  /// Create our main App instance.
  ///
  app_ = App::Create();

  ///
  /// Create a resizable window by passing by OR'ing our window flags with
  /// kWindowFlags_Resizable.
  ///
  window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT,
    false, kWindowFlags_Titled | kWindowFlags_Resizable);

  ///
  /// Set the title of our window.
  ///
  window_->SetTitle("Co-Sequential-Processing");

  ///
  /// Tell our app to use 'window' as our main window.
  ///
  /// This call is required before creating any overlays or calling App::Run
  ///
  app_->set_window(*window_.get());

  ///
  /// Create our HTML overlay-- we don't care about its initial size and
  /// position because it'll be calculated when we call OnResize() below.
  ///
  overlay_ = Overlay::Create(*window_.get(), 1, 1, 0, 0);

  ///
  /// Force a call to OnResize to perform size/layout of our overlay.
  ///
  OnResize(window_->width(), window_->height());

  ///
  /// Load a page into our overlay's View
  ///
  overlay_->view()->LoadURL("file:///html/MasterRecordManager.html");

  ///
  /// Register our MyApp instance as an AppListener so we can handle the
  /// App's OnUpdate event below.
  ///
  app_->set_listener(this);

  ///
  /// Register our MyApp instance as a WindowListener so we can handle the
  /// Window's OnResize event below.
  ///
  window_->set_listener(this);

  ///
  /// Register our MyApp instance as a LoadListener so we can handle the
  /// View's OnFinishLoading and OnDOMReady events below.
  ///
  overlay_->view()->set_load_listener(this);
}

MyApp::~MyApp() {
}

void MyApp::Run() {
  app_->Run();
}

void MyApp::OnUpdate() {
}

void MyApp::OnClose() {
}

void MyApp::OnResize(uint32_t width, uint32_t height) {
  overlay_->Resize(width, height);
}

void MyApp::OnFinishLoading(View* caller) {
}

void addFunction(const char functionname[],JSContextRef ctx,JSObjectCallAsFunctionCallback function){
    // Create a JavaScript String containing the name of our callback.
  JSStringRef name = JSStringCreateWithUTF8CString(functionname);
  // Create a garbage-collected JavaScript function that is bound to our
  // native C callback 'OnButtonClick()'.
  JSObjectRef func = JSObjectMakeFunctionWithCallback(ctx, name,function);
  // Get the global JavaScript object (aka 'window')
  JSObjectRef globalObj = JSContextGetGlobalObject(ctx);
  // Store our function in the page's global JavaScript object so that it
  // accessible from the page as 'OnButtonClick()'.
  JSObjectSetProperty(ctx, globalObj, name, func, 0, 0);
  // Release the JavaScript String we created earlier.
  JSStringRelease(name);
}


void MyApp::OnDOMReady(View* caller) {
  JSContextRef ctx = caller->js_context();
  addFunction("addMasterRecord",ctx,addMasterRecord);
  addFunction("getMasterRecordData",ctx,getMasterRecord);
  addFunction("deleteMasterRecord",ctx,deleteMasterRecord);
  addFunction("addTransaction",ctx,addTransaction);
  addFunction("getTransaction",ctx,getTransaction);
  addFunction("deleteTransaction",ctx,deleteTransaction);
  addFunction("genLedger",ctx,genLedger);
}
