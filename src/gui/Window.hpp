#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <wx-3.0/wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx-3.0/wx/wx.h>
#endif

class Window : public wxApp{
public:
    virtual bool OnInit();
};

class Frame : public wxFrame{
public:
    Frame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

enum
{
    ID_Hello = 1
};


#endif //WINDOW_HPP