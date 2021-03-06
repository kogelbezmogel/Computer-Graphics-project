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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/filepicker.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/bmpbuttn.h>
#include <wx/sizer.h>
#include <wx/clrpicker.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxButton* m_nextbutton;
		wxButton* m_save_button;
		wxButton* m_undo_button;
		wxButton* m_display_animation_button;
		wxFilePickerCtrl* m_filePicker;
		wxStaticText* m_sliderTEXT;
		wxSlider* m_slider;
		wxBitmapButton* m_circle_button;
		wxBitmapButton* m_broken_line_button;
		wxBitmapButton* m_curve_line_button;
		wxBitmapButton* m_ellipse_button;
		wxBitmapButton* m_square_button;
		wxBitmapButton* m_triangle_button;
		wxStaticText* m_line_colourTEXT;
		wxColourPickerCtrl* m_line_colour;
		wxStaticText* m_fill_colourTEXT;
		wxColourPickerCtrl* m_fill_colour;
		wxCheckBox* m_fill_button;
		wxPanel* m_panel;

		// Virtual event handlers, overide them in your derived class
		virtual void m_next_frame_button_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_save_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_undo_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_display_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choosing_bacground_file( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void m_slider_change( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_circle_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_broken_line_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_curve_line_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_ellipse_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_square_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_triangle_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_fill_button_check( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_left_click_on_panel( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_mouse_on_panel_moved( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_right_click_on_panel( wxMouseEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("27 Time-lapse animation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 750,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AnimationFrame
///////////////////////////////////////////////////////////////////////////////
class AnimationFrame : public wxFrame
{
	private:

	protected:
		wxButton* m_stop_button;
		wxButton* m_start_button;
		wxButton* m_restart_button;
		wxFilePickerCtrl* m_animation_file_picker;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_animation_speed_textxtctr;
		wxStaticText* m_staticText4;
		wxSlider* m_slider2;
		wxStaticText* m_staticText5;
		wxPanel* m_animation_panel;

		// Virtual event handlers, overide them in your derived class
		virtual void m_stop_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_start_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_restatr_button_clicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_new_animation_file_selected( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void m_speed_slider_changed( wxScrollEvent& event ) { event.Skip(); }


	public:

		AnimationFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,620 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~AnimationFrame();

};

