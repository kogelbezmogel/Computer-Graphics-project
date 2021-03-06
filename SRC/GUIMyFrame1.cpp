#include "GUIMyFrame1.h"
#include "GUIAnimationFrame.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_next_frame_button_click(wxCommandEvent& event)
{
	save_vector_to_file();
	m_shapes.clear();
	paint_on_wxpanel();
}

void GUIMyFrame1::m_save_button_clicked( wxCommandEvent& event )
{
	save_vector_to_file();
}

void GUIMyFrame1::m_undo_button_clicked(wxCommandEvent& event)
{
	if (!m_shapes.empty())
		m_shapes.pop_back();
	paint_on_wxpanel();
}

void GUIMyFrame1::m_display_button_clicked(wxCommandEvent& event)
{
	wxFrame* animationFrame = new GUIAnimationFrame(NULL);
	animationFrame->Show(true);
}

void GUIMyFrame1::m_choosing_bacground_file(wxFileDirPickerEvent& event)
{
	std::string path_to_file = m_filePicker->GetPath();

	std::shared_ptr<wxImage> image_org(new wxImage(path_to_file));
	m_background_image_org = image_org;

	std::shared_ptr<wxImage> image_dis(new wxImage(path_to_file));
	m_background_image_dis = image_dis;

	correct_brightness(*m_background_image_dis);

	paint_on_wxpanel();
}

void GUIMyFrame1::m_slider_change(wxScrollEvent& event)
{
	if (m_background_image_dis) {

		*m_background_image_dis = m_background_image_org->Copy();
		correct_brightness(*m_background_image_dis);
	}
	paint_on_wxpanel();
}

void GUIMyFrame1::m_circle_button_clicked(wxCommandEvent& event)
{
	m_drawing_flag = CIRCLE;
	reset_bitmap_buttons();
	m_circle_button->SetBitmap(wxBitmap(wxT("ikony/okrag_s.png"), wxBITMAP_TYPE_ANY));
}

void GUIMyFrame1::m_broken_line_button_clicked(wxCommandEvent& event)
{
	m_drawing_flag = BROKEN_LINE;
	reset_bitmap_buttons();
	m_broken_line_button->SetBitmap(wxBitmap(wxT("ikony/lamana_s.png"), wxBITMAP_TYPE_ANY));
}

void GUIMyFrame1::m_curve_line_button_clicked(wxCommandEvent& event)
{
	m_drawing_flag = CURVE_LINE;
	reset_bitmap_buttons();
	m_curve_line_button->SetBitmap(wxBitmap(wxT("ikony/krzywa_s.png"), wxBITMAP_TYPE_ANY));
}

void GUIMyFrame1::m_ellipse_button_clicked(wxCommandEvent& event)
{
	m_drawing_flag = ELLIPSE;
	reset_bitmap_buttons();
	m_ellipse_button->SetBitmap(wxBitmap(wxT("ikony/elipsa_s.png"), wxBITMAP_TYPE_ANY));
}

void GUIMyFrame1::m_square_button_clicked(wxCommandEvent& event)
{
	m_drawing_flag = SQUARE;
	reset_bitmap_buttons();
	m_square_button->SetBitmap(wxBitmap(wxT("ikony/kwadrat_s.png"), wxBITMAP_TYPE_ANY));
}

void GUIMyFrame1::m_triangle_button_clicked(wxCommandEvent& event)
{
	m_drawing_flag = TRIANGLE;
	reset_bitmap_buttons();
	m_triangle_button->SetBitmap(wxBitmap(wxT("ikony/trojkat_s.png"), wxBITMAP_TYPE_ANY));
}

void GUIMyFrame1::m_fill_button_check(wxCommandEvent& event)
{
	if (!m_fill)
	{
		m_fill = true;
		m_actual_shape.setFilled(m_fill_colour->GetColour());
	}
	else
	{
		m_actual_shape.setFilled(*wxTRANSPARENT_BRUSH);
		m_fill = false;
	}
}

void GUIMyFrame1::m_left_click_on_panel(wxMouseEvent& event)
{

	int mouseY;
	int mouseX;


	switch (m_drawing_flag) {


	case CIRCLE:
		if (m_first_click_flag) {

			m_first_click_flag = false;
			m_actual_shape.setKind(CIRCLE);

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled(m_fill_colour->GetColour());
		}
		else {
			m_first_click_flag = true;

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case TRIANGLE:

		if (m_first_click_flag) {

			m_first_click_flag = false;
			m_actual_shape.setKind(TRIANGLE);

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled(m_fill_colour->GetColour());
		}
		else {
			m_first_click_flag = true;

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case SQUARE:

		if (m_first_click_flag) {
			m_first_click_flag = false;
			m_actual_shape.setKind(SQUARE);

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled(m_fill_colour->GetColour());
		}
		else {
			m_first_click_flag = true;

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case ELLIPSE:

		if (m_first_click_flag) {
			m_first_click_flag = false;
			m_actual_shape.setKind(ELLIPSE);


			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled(m_fill_colour->GetColour());
		}
		else {
			m_first_click_flag = true;

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case BROKEN_LINE:

		if (m_first_click_flag) {
			m_first_click_flag = false;
			m_actual_shape.setKind(BROKEN_LINE);

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			if (m_fill_button->IsChecked())
				m_actual_shape.setFilled(m_fill_colour->GetColour());
		}
		else {
			m_first_click_flag = true;

			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;

	case CURVE_LINE:

		mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
		mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;

		if (m_first_click_flag == true && m_second_click_flag == false) {

			m_first_click_flag = false;
			m_second_click_flag = true;
			m_actual_shape.setKind(CURVE_LINE);

			m_actual_shape.push_back(wxPoint(mouseX, mouseY));

		}
		else if (m_second_click_flag == true && m_first_click_flag == false) {

			m_second_click_flag = false;
			m_actual_shape.push_back(wxPoint(mouseX, mouseY));
		}
		else if (m_second_click_flag == false && m_first_click_flag == false) {

			m_first_click_flag = true;
			m_second_click_flag = false;

			m_actual_shape.push_back(wxPoint(mouseX, mouseY));
			m_shapes.push_back(m_actual_shape);
			m_actual_shape.clear();
		}
		break;
	}
}

void GUIMyFrame1::m_mouse_on_panel_moved(wxMouseEvent& event)
{
	if (m_first_click_flag == false)
		paint_on_wxpanel();

}

void GUIMyFrame1::m_right_click_on_panel(wxMouseEvent& event)
{

	switch (m_drawing_flag) {

	case CIRCLE:
	case TRIANGLE:
	case SQUARE:
	case ELLIPSE:
	case BROKEN_LINE:
	case CURVE_LINE:
		m_first_click_flag = true;
		m_actual_shape.clear();
		paint_on_wxpanel();
		break;

	default:
		break;
	}

}


void GUIMyFrame1::reset_bitmap_buttons() 
{
	m_circle_button->SetBitmap(wxBitmap(wxT("ikony/okrag.png"), wxBITMAP_TYPE_ANY));
	m_broken_line_button->SetBitmap(wxBitmap(wxT("ikony/lamana.png"), wxBITMAP_TYPE_ANY));
	m_curve_line_button->SetBitmap(wxBitmap(wxT("ikony/krzywa.png"), wxBITMAP_TYPE_ANY));
	m_ellipse_button->SetBitmap(wxBitmap(wxT("ikony/elipsa.png"), wxBITMAP_TYPE_ANY));
	m_square_button->SetBitmap(wxBitmap(wxT("ikony/kwadrat.png"), wxBITMAP_TYPE_ANY));
	m_triangle_button->SetBitmap(wxBitmap(wxT("ikony/trojkat.png"), wxBITMAP_TYPE_ANY));
}

void GUIMyFrame1::correct_brightness(wxImage& image_to_change) 
{
	int data_length = 3 * image_to_change.GetHeight() * image_to_change.GetWidth();
	int current = 0;
	double bright_value = m_slider->GetValue();
	unsigned char* image_data = image_to_change.GetData();

	for (int i = 0; i < data_length; ++i) {
		current = image_data[i] + bright_value;
		if (current < 0)
			image_data[i] = 0;
		else if (current > 255)
			image_data[i] = 255;
		else
			image_data[i] = current;
	}
	m_background_bitmap = wxBitmap(image_to_change);
}

void GUIMyFrame1::paint_on_wxpanel() 
{
	std::shared_ptr<wxClientDC> DC(new wxClientDC(m_panel));
	wxPoint tab[3];
	DC->Clear();
	if (m_background_image_dis) {
		DC->DrawBitmap( m_background_bitmap, 0, 0, true );
	}
	else {
		m_panel->SetBackgroundColour(wxColour(*wxWHITE));
	}

	int mouseX;
	int mouseY;
	

	draw_vector_with_dc(DC, m_shapes);

	switch (m_actual_shape.getKind()) {

	case CIRCLE:
		double radious;
		if (m_first_click_flag == false) { 
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			radious = sqrt(pow(m_actual_shape[0].x - mouseX, 2) + pow(m_actual_shape[0].y - mouseY, 2));
		}
		if (m_fill == false)
			DC->SetBrush(*wxTRANSPARENT_BRUSH);
		else
			DC->SetBrush(m_actual_shape.GetColour());

		m_actual_shape.SetLine(m_line_colour->GetColour());
		DC->SetPen(wxPen(m_actual_shape.GetLine(), 3));
		DC->DrawCircle(m_actual_shape[0], radious);
		break;

	case SQUARE:
		double d;
		if (m_first_click_flag == false) {
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;
			d = std::max(mouseX-m_actual_shape[0].x , mouseY-m_actual_shape[0].y );
		}
		if (m_fill == false)
			DC->SetBrush(*wxTRANSPARENT_BRUSH);
		else
			DC->SetBrush(m_actual_shape.GetColour());
		m_actual_shape.SetLine(m_line_colour->GetColour());
		DC->SetPen(wxPen(m_actual_shape.GetLine(), 3));
		DC->DrawRectangle(m_actual_shape[0].x, m_actual_shape[0].y, d, d);
		break;

	case ELLIPSE :
		double f,g;
		if (m_first_click_flag == false) {
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;

			f = mouseX - m_actual_shape[0].x;
			g = mouseY - m_actual_shape[0].y;
		}
		if (m_fill == false)
			DC->SetBrush(*wxTRANSPARENT_BRUSH);
		else
			DC->SetBrush(m_actual_shape.GetColour());
		m_actual_shape.SetLine(m_line_colour->GetColour());
		DC->SetPen(wxPen(m_actual_shape.GetLine(), 3));
		DC->DrawEllipse(m_actual_shape[0].x, m_actual_shape[0].y,f, g);
		break;

	case TRIANGLE:
		double x;
		if (m_first_click_flag == false) {
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;

			x = mouseX - m_actual_shape[0].x;
			x = x/2+m_actual_shape[0].x;
			tab[0] = wxPoint(m_actual_shape[0].x, mouseY);
			tab[2] = wxPoint(mouseX, mouseY);
			tab[1] = wxPoint(x, m_actual_shape[0].y);

		}

		if (m_fill == false)
			DC->SetBrush(*wxTRANSPARENT_BRUSH);
		else
			DC->SetBrush(m_actual_shape.GetColour());

		m_actual_shape.SetLine(m_line_colour->GetColour());
		DC->SetPen(wxPen(m_actual_shape.GetLine(), 3));
		DC->DrawPolygon(3, tab);
		break;
	case BROKEN_LINE :
		
		if (m_first_click_flag == false) {
			mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
			mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;	

		}

		m_actual_shape.SetLine(m_line_colour->GetColour());
		DC->SetPen(wxPen(m_actual_shape.GetLine(), 3));

		DC->DrawLine(m_actual_shape[0].x, m_actual_shape[0].y, mouseX, mouseY);
		break;

	case CURVE_LINE:

		m_actual_shape.SetLine(m_line_colour->GetColour());
		DC->SetPen(wxPen(m_actual_shape.GetLine(), 3));

		mouseX = wxGetMousePosition().x - m_panel->GetScreenPosition().x;
		mouseY = wxGetMousePosition().y - m_panel->GetScreenPosition().y;

		if (m_first_click_flag == false && m_second_click_flag == true){
			DC->DrawLine(m_actual_shape[0], wxPoint(mouseX, mouseY));
		}
		else if (m_first_click_flag == false && m_second_click_flag == false)
			DC->DrawSpline(m_actual_shape[0].x, m_actual_shape[0].y, mouseX, mouseY, m_actual_shape[1].x, m_actual_shape[1].y);
		break;

	default:
		break;
	}
}

void GUIMyFrame1::save_vector_to_file(std::string file_name)
{
	std::string tekst;
	std::string first_line;
	std::string temp_line;
	std::string save_line;
	std::string path_to_background;
	std::string brightness_value;

	std::fstream plik;
	std::vector<std::string> lines;
	int frames{0};

	plik.open(file_name, std::ios::in);

	if (plik.good()) {
		
		getline(plik, first_line);
		frames = stoi(first_line);

		while (getline(plik, temp_line)) {
			lines.push_back(temp_line);
		}
	}
	plik.close();

	path_to_background = m_filePicker->GetPath();

	if (path_to_background == "")
		path_to_background = "NULL";
	else
		convert_to_relative_path(path_to_background);

	brightness_value = std::to_string(m_slider->GetValue());
	save_line = path_to_background + " " + brightness_value + " ";

	for (auto shape : m_shapes) {
		save_line += shape.txt_code();
	}
	save_line += "\n";

	++frames;
	lines.push_back(save_line);

	plik.open(file_name, std::ios::out);

	if (plik.good()) {
		plik << frames << std::endl;
		for (auto line : lines)
			plik << line << std::endl;
	}
}

