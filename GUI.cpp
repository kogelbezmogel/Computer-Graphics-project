///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_background_picker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.png ; *.jpg"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_background_picker, 0, wxALL|wxEXPAND, 5 );

	m_next_frame_button = new wxButton( this, wxID_ANY, wxT("Next Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_next_frame_button, 0, wxALL|wxEXPAND, 5 );

	m_previous_frame_button = new wxButton( this, wxID_ANY, wxT("Previous Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_previous_frame_button, 0, wxALL|wxEXPAND, 5 );

	m_clear_button = new wxButton( this, wxID_ANY, wxT("Clear Frame"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_clear_button, 0, wxALL|wxEXPAND, 5 );

	m_back_button = new wxButton( this, wxID_ANY, wxT("Back"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_back_button, 0, wxALL|wxEXPAND, 5 );

	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );

	m_circle_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 40,40 ), wxBU_AUTODRAW|0 );
	gSizer1->Add( m_circle_button, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_bpButton2 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 40,40 ), wxBU_AUTODRAW|0 );
	gSizer1->Add( m_bpButton2, 0, wxALL, 5 );

	m_square_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 40,40 ), wxBU_AUTODRAW|0 );
	gSizer1->Add( m_square_button, 0, wxALL, 5 );

	m_triangle_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 40,40 ), wxBU_AUTODRAW|0 );
	gSizer1->Add( m_triangle_button, 0, wxALL, 5 );

	m_broken_line_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 40,40 ), wxBU_AUTODRAW|0 );
	gSizer1->Add( m_broken_line_button, 0, wxALL, 5 );

	m_curve_line_button = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 40,40 ), wxBU_AUTODRAW|0 );
	gSizer1->Add( m_curve_line_button, 0, wxALL, 5 );


	bSizer2->Add( gSizer1, 0, wxEXPAND, 5 );

	m_line_color_picker = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer2->Add( m_line_color_picker, 0, wxALL, 5 );

	m_filling_color_picker = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	bSizer2->Add( m_filling_color_picker, 0, wxALL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	m_main_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_main_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	bSizer1->Add( m_main_panel, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_next_frame_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_next_frame_button_clicked ), NULL, this );
	m_previous_frame_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_previous_button_clicked ), NULL, this );
	m_clear_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_clear_button_clicked ), NULL, this );
	m_back_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_back_button_clicked ), NULL, this );
	m_circle_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_circle_button_clicked ), NULL, this );
	m_square_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_square_button_clicked ), NULL, this );
	m_triangle_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_triangle_button_clicked ), NULL, this );
	m_broken_line_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_broken_line_clicked ), NULL, this );
	m_curve_line_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_curve_line_clicked ), NULL, this );
	m_main_panel->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::m_double_left_click_on_panel ), NULL, this );
	m_main_panel->Connect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::m_coursor_moved_on_panel ), NULL, this );
	m_main_panel->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( MainFrame::m_right_clicked_on_panel ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_next_frame_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_next_frame_button_clicked ), NULL, this );
	m_previous_frame_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_previous_button_clicked ), NULL, this );
	m_clear_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_clear_button_clicked ), NULL, this );
	m_back_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_back_button_clicked ), NULL, this );
	m_circle_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_circle_button_clicked ), NULL, this );
	m_square_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_square_button_clicked ), NULL, this );
	m_triangle_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_triangle_button_clicked ), NULL, this );
	m_broken_line_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_broken_line_clicked ), NULL, this );
	m_curve_line_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_curve_line_clicked ), NULL, this );
	m_main_panel->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MainFrame::m_double_left_click_on_panel ), NULL, this );
	m_main_panel->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::m_coursor_moved_on_panel ), NULL, this );
	m_main_panel->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( MainFrame::m_right_clicked_on_panel ), NULL, this );

}
