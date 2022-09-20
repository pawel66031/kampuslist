#include "Window.hpp"

bool Window::OnInit(){
    Frame *frame = new Frame();
    frame->Show(true);
    return true;
}

Frame::Frame()
    : wxFrame(NULL, wxID_ANY, "Hello World")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello..\tCtrl-H",
                        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to exWidgets");

    Bind(wxEVT_MENU, &Frame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
}

void Frame::OnExit(wxCommandEvent& event){
    Close(true);
}

void Frame::OnAbout(wxCommandEvent& event){
    wxMessageBox("This is a wxWidgets Hello World example",
                "About Hello World", wxOK | wxICON_INFORMATION);
}

void Frame::OnHello(wxCommandEvent& event){
    wxLogMessage("Hello world from wxWidgets!");
}