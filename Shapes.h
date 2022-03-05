#pragma once

#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#include <wx/dcbuffer.h>
#include <wx/gdicmn.h>

////////////////////////////////////interface
class Shape {

public:
	Shape();
	virtual ~Shape() { };
	virtual void draw(wxBufferedDC* bufDC) = 0;
	virtual void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) = 0;
	virtual void move_frame(int x, int y) = 0;

	void push_point(wxPoint point);
	void pop_point();

	wxPoint& get_start();
	wxPoint& get_end();

	
protected:
	virtual void set_ready() = 0;
	std::vector<wxPoint> m_points;
	std::vector< std::shared_ptr<Shape> > m_conncetions;
	wxPoint m_center{ 0 ,0 };
};

Shape::Shape() { }

void Shape::push_point(wxPoint point) {


	if (m_points.size() == 0) {
		m_points.push_back(point);
	}
	else if (m_points.size() > 0) {
		set_ready();
		m_points.push_back(point);
	}
	else if (m_points.size() > 1) {
		m_points.pop_back();
		m_points.push_back(point);
	}
}

void Shape::pop_point() {
	m_points.pop_back();
}

void Shape::move_frame(int x, int y) {

	for (auto& i : m_points) {
		i.x += x;
		i.y += y;
	}
}

wxPoint& Shape::get_start() {
	return m_points[0];
}

wxPoint& Shape::get_end() {
	return m_points[1];
}

//////////////////////////interface_end



/////////////////CIRCLE
class Circle : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;

private:
	void set_ready();
	int m_r{ 0 };
};

void Circle::draw(wxBufferedDC* buffDC) {
	buffDC->DrawCircle(m_center, m_r);
}

void Circle::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {
		int r = sqrt(pow(end_point.x - m_points[0].x, 2) + pow(end_point.y - m_points[1].y, 2));
		bufDC->DrawCircle(m_points[0], r);
	}
}

void Circle::set_ready() {

}

/////////////////SQUARE
class Square : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;

private:
	void set_ready() override;
	int m_a{ 0 };
};

void Square::draw(wxBufferedDC* buffDC) {
	buffDC->DrawRectangle(m_points[0].x, m_points[0].y, m_points[0].x + m_a, m_points[0].y + m_a);
}

void Square::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {
		int a = std::max(end_point.x - m_points[0].x, end_point.y - m_points[1].y);
		bufDC->DrawRectangle(m_points[0].x, m_points[0].y, m_points[0].x + a, m_points[0].y + a);
	}
}

void Square::set_ready() {

}

/////////////////ELLIPSE
class Ellipse : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;

private:
	void set_ready() override;

	int m_a{ 0 };
	int m_b{ 0 };
};

void Ellipse::draw(wxBufferedDC* buffDC) {

}

void Ellipse::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {
		int h = end_point.y - m_points[0].y;
		int l = end_point.x - m_points[0].x;
		bufDC->DrawEllipse(m_points[0].x, m_points[0].y, l, h);
	}
}

void Ellipse::set_ready() {

}

/////////////////RECTANGLE
class Rectangle : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;

private:
	void set_ready() override;

	int m_a{ 0 };
	int m_b{ 0 };
};

void Rectangle::draw(wxBufferedDC* buffDC) {
	buffDC->DrawRectangle(m_points[0].x, m_points[0].y, m_points[1].x, m_points[1].y);
}

void Rectangle::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {

	}
}

void Rectangle::set_ready() {

}


/////////////////TRIANGLE_REC
class Triangle_rec : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;
private:

	void set_ready() override;
	
};

void Triangle_rec::draw(wxBufferedDC* buffDC) {

}

void Triangle_rec::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {
		int h = end_point.y - m_points[0].y;
		int l = end_point.x - m_points[0].x;
		bufDC->DrawLine(m_points[0].x, m_points[0].y, m_points[0].x, m_points[0].y + h);
		bufDC->DrawLine(m_points[0].x, m_points[0].y + h, m_points[0].x + l, m_points[0].y + h);
		bufDC->DrawLine(m_points[0].x, m_points[0].y, m_points[0].x + l, m_points[0].y + h);
	}
}

void Triangle_rec::set_ready() {

}

/////////////////TRIANGLE_ISO
class Triangle_iso : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;
private:
	void set_ready() override;
};

void Triangle_iso::draw(wxBufferedDC* buffDC) {

}

void Triangle_iso::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {
		int h = end_point.y - m_points[0].y;
		int l = end_point.x - m_points[0].x;
		bufDC->DrawLine(m_points[0].x, m_points[0].y + h, m_points[0].x + l, m_points[0].y + h);
		bufDC->DrawLine(m_points[0].x, m_points[0].y + h, m_points[0].x + l / 2, m_points[0].y);
		bufDC->DrawLine(m_points[0].x + l / 2, m_points[0].y, m_points[0].x + l, m_points[0].y + h);
	}
}

void Triangle_iso::set_ready() {

}

/////////////////BROKEN_LINE
class Broken_line : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;

private:
	void set_ready() override;
};

void Broken_line::draw(wxBufferedDC* buffDC) {

}

void Broken_line::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {
		bufDC->DrawLine(m_points[0], end_point);
	}
}

void Broken_line::set_ready() {

}

/////////////////CURVE_LINE
class Curve_line : public Shape {

public:
	void draw(wxBufferedDC* buffDC) override;
	void draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) override;

private:
	void set_ready() override;
};



void Curve_line::draw(wxBufferedDC* buffDC) {

}

void Curve_line::draw_unended(wxBufferedDC* bufDC, wxPoint& end_point) {

	if (!m_points.empty()) {

	}
}

void Curve_line::set_ready() {

}



