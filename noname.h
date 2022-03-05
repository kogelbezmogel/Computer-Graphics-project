///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/filepicker.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/bmpbuttn.h>
#include <wx/sizer.h>
#include <wx/clrpicker.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxFilePickerCtrl* m_background_picker;
		wxButton* m_next_frame_button;
		wxButton* m_previous_frame_button;
		wxButton* m_clear_button;
		wxButton* m_back_button;
		wxBitmapButton* m_circle_button;
		wxBitmapButton* m_bpButton2;
		wxBitmapButton* m_square_button;
		wxBitmapButton* m_triangle_button;
		wxBitmapButton* m_broken_line_button;
		wxBitmapButton* m_curve_line_button;
		wxColourPickerCtrl* m_line_color_picker;
		wxColourPickerCtrl* m_filling_color_picker;
		wxPanel* m_main_panel;

		// Virtual event handlers, overide them in your derived class
		virtual void m_next_frame_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_previous_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_clear_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_back_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_circle_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_square_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_triangle_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_broken_line_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_curve_line_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_double_left_click_on_panel( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_coursor_moved_on_panel( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_right_clicked_on_panel( wxMouseEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

