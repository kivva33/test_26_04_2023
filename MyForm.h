#pragma once
#include "windows.h"
#include "cassert"
#include "cmath"

namespace labaaftergraphics {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Сводка для MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            pb_for_clock->Image = gcnew Bitmap(pb_for_clock->Width, pb_for_clock->Height);
            b = gcnew SolidBrush(Color::White);
            pn_contour = gcnew Pen(Color::Black, 3);
            pn_arrows = gcnew Pen(Color::Coral, 3);
            edit = gcnew array<float, 2>(3, 3);
            identity_mat(edit);
            center.X = 0, center.Y = 0;
            //
            //TODO: добавьте код конструктора
            //
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
            delete MyPoint;
        }

    private: System::Windows::Forms::PictureBox^ pb_for_clock;
    private: System::Windows::Forms::ListBox^ lb_Point;
    private: System::Windows::Forms::Button^ btn_many_coal;
    private: System::Windows::Forms::Button^ btn_clear;
    private: System::Windows::Forms::Button^ btn_rotate_center;

    private: System::Windows::Forms::Label^ lbl_rotate;
    private: System::Windows::Forms::TextBox^ tb_rotate;
    private: System::Windows::Forms::Button^ btn_scale;
    private: System::Windows::Forms::Label^ lbl_scale;
    private: System::Windows::Forms::TextBox^ tb_scale;
    private: System::Windows::Forms::Button^ btn_gorizontal;
    private: System::Windows::Forms::Button^ btn_vertical;
    private: System::Windows::Forms::Label^ lbl_gorizontal;
    private: System::Windows::Forms::TextBox^ tb_gorizontal;
    private: System::Windows::Forms::Label^ lbl_vertical;
    private: System::Windows::Forms::TextBox^ tb_vertical;
    private: System::Windows::Forms::Label^ lbl_start;
    private: System::Windows::Forms::TextBox^ tb_start;
    private: System::Windows::Forms::Button^ btn_start;
    private: System::Windows::Forms::Button^ btn_center;
    private: System::Windows::Forms::Button^ btn_scale_gor;

    private: System::Windows::Forms::Button^ btn_scale_vert;






    protected:


    private:
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->pb_for_clock = (gcnew System::Windows::Forms::PictureBox());
            this->lb_Point = (gcnew System::Windows::Forms::ListBox());
            this->btn_many_coal = (gcnew System::Windows::Forms::Button());
            this->btn_clear = (gcnew System::Windows::Forms::Button());
            this->btn_rotate_center = (gcnew System::Windows::Forms::Button());
            this->lbl_rotate = (gcnew System::Windows::Forms::Label());
            this->tb_rotate = (gcnew System::Windows::Forms::TextBox());
            this->btn_scale = (gcnew System::Windows::Forms::Button());
            this->lbl_scale = (gcnew System::Windows::Forms::Label());
            this->tb_scale = (gcnew System::Windows::Forms::TextBox());
            this->btn_gorizontal = (gcnew System::Windows::Forms::Button());
            this->btn_vertical = (gcnew System::Windows::Forms::Button());
            this->lbl_gorizontal = (gcnew System::Windows::Forms::Label());
            this->tb_gorizontal = (gcnew System::Windows::Forms::TextBox());
            this->lbl_vertical = (gcnew System::Windows::Forms::Label());
            this->tb_vertical = (gcnew System::Windows::Forms::TextBox());
            this->lbl_start = (gcnew System::Windows::Forms::Label());
            this->tb_start = (gcnew System::Windows::Forms::TextBox());
            this->btn_start = (gcnew System::Windows::Forms::Button());
            this->btn_center = (gcnew System::Windows::Forms::Button());
            this->btn_scale_gor = (gcnew System::Windows::Forms::Button());
            this->btn_scale_vert = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_for_clock))->BeginInit();
            this->SuspendLayout();
            //
            // pb_for_clock
            //
            this->pb_for_clock->Location = System::Drawing::Point(12, 12);
            this->pb_for_clock->Name = L"pb_for_clock";
            this->pb_for_clock->Size = System::Drawing::Size(500, 500);
            this->pb_for_clock->TabIndex = 1;
            this->pb_for_clock->TabStop = false;
            this->pb_for_clock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pb_for_clock_MouseDown);
            //
            // lb_Point
            //
            this->lb_Point->FormattingEnabled = true;
            this->lb_Point->ItemHeight = 16;
            this->lb_Point->Location = System::Drawing::Point(542, 12);
            this->lb_Point->Name = L"lb_Point";
            this->lb_Point->Size = System::Drawing::Size(120, 196);
            this->lb_Point->TabIndex = 2;
            //
            // btn_many_coal
            //
            this->btn_many_coal->Location = System::Drawing::Point(524, 357);
            this->btn_many_coal->Name = L"btn_many_coal";
            this->btn_many_coal->Size = System::Drawing::Size(122, 73);
            this->btn_many_coal->TabIndex = 3;
            this->btn_many_coal->Text = L"построить многоугольник";
            this->btn_many_coal->UseVisualStyleBackColor = true;
            this->btn_many_coal->Click += gcnew System::EventHandler(this, &MyForm::btn_many_coal_Click);
            //
            // btn_clear
            //
            this->btn_clear->Location = System::Drawing::Point(524, 436);
            this->btn_clear->Name = L"btn_clear";
            this->btn_clear->Size = System::Drawing::Size(122, 35);
            this->btn_clear->TabIndex = 4;
            this->btn_clear->Text = L"Очистить";
            this->btn_clear->UseVisualStyleBackColor = true;
            this->btn_clear->Click += gcnew System::EventHandler(this, &MyForm::btn_clear_Click);
            //
            // btn_rotate_center
            //
            this->btn_rotate_center->Location = System::Drawing::Point(678, 58);
            this->btn_rotate_center->Name = L"btn_rotate_center";
            this->btn_rotate_center->Size = System::Drawing::Size(106, 52);
            this->btn_rotate_center->TabIndex = 5;
            this->btn_rotate_center->Text = L"Повернуть на угол";
            this->btn_rotate_center->UseVisualStyleBackColor = true;
            this->btn_rotate_center->Click += gcnew System::EventHandler(this, &MyForm::btn_rotate_center_Click);
            //
            // lbl_rotate
            //
            this->lbl_rotate->AutoSize = true;
            this->lbl_rotate->Location = System::Drawing::Point(801, 59);
            this->lbl_rotate->Name = L"lbl_rotate";
            this->lbl_rotate->Size = System::Drawing::Size(103, 16);
            this->lbl_rotate->TabIndex = 6;
            this->lbl_rotate->Text = L"угол поворота";
            //
            // tb_rotate
            //
            this->tb_rotate->Location = System::Drawing::Point(801, 78);
            this->tb_rotate->Name = L"tb_rotate";
            this->tb_rotate->Size = System::Drawing::Size(100, 22);
            this->tb_rotate->TabIndex = 7;
            //
            // btn_scale
            //
            this->btn_scale->Location = System::Drawing::Point(678, 116);
            this->btn_scale->Name = L"btn_scale";
            this->btn_scale->Size = System::Drawing::Size(106, 55);
            this->btn_scale->TabIndex = 8;
            this->btn_scale->Text = L"Изменить масштаб";
            this->btn_scale->UseVisualStyleBackColor = true;
            this->btn_scale->Click += gcnew System::EventHandler(this, &MyForm::btn_scale_Click);
            //
            // lbl_scale
            //
            this->lbl_scale->AutoSize = true;
            this->lbl_scale->Location = System::Drawing::Point(801, 116);
            this->lbl_scale->Name = L"lbl_scale";
            this->lbl_scale->Size = System::Drawing::Size(167, 16);
            this->lbl_scale->TabIndex = 9;
            this->lbl_scale->Text = L"Коэффициент масштаба";
            //
            // tb_scale
            //
            this->tb_scale->Location = System::Drawing::Point(801, 135);
            this->tb_scale->Name = L"tb_scale";
            this->tb_scale->Size = System::Drawing::Size(100, 22);
            this->tb_scale->TabIndex = 10;
            //
            // btn_gorizontal
            //
            this->btn_gorizontal->Location = System::Drawing::Point(678, 177);
            this->btn_gorizontal->Name = L"btn_gorizontal";
            this->btn_gorizontal->Size = System::Drawing::Size(106, 45);
            this->btn_gorizontal->TabIndex = 11;
            this->btn_gorizontal->Text = L"сдвинуть по горизонтали";
            this->btn_gorizontal->UseVisualStyleBackColor = true;
            this->btn_gorizontal->Click += gcnew System::EventHandler(this, &MyForm::btn_gorizontal_Click);
            //
            // btn_vertical
            //
            this->btn_vertical->Location = System::Drawing::Point(678, 229);
            this->btn_vertical->Name = L"btn_vertical";
            this->btn_vertical->Size = System::Drawing::Size(106, 43);
            this->btn_vertical->TabIndex = 12;
            this->btn_vertical->Text = L"сдвинуть по вертикали";
            this->btn_vertical->UseVisualStyleBackColor = true;
            this->btn_vertical->Click += gcnew System::EventHandler(this, &MyForm::btn_vertical_Click);
            //
            // lbl_gorizontal
            //
            this->lbl_gorizontal->AutoSize = true;
            this->lbl_gorizontal->Location = System::Drawing::Point(798, 177);
            this->lbl_gorizontal->Name = L"lbl_gorizontal";
            this->lbl_gorizontal->Size = System::Drawing::Size(95, 16);
            this->lbl_gorizontal->TabIndex = 13;
            this->lbl_gorizontal->Text = L"длина сдвига";
            //
            // tb_gorizontal
            //
            this->tb_gorizontal->Location = System::Drawing::Point(801, 200);
            this->tb_gorizontal->Name = L"tb_gorizontal";
            this->tb_gorizontal->Size = System::Drawing::Size(100, 22);
            this->tb_gorizontal->TabIndex = 14;
            //
            // lbl_vertical
            //
            this->lbl_vertical->AutoSize = true;
            this->lbl_vertical->Location = System::Drawing::Point(801, 229);
            this->lbl_vertical->Name = L"lbl_vertical";
            this->lbl_vertical->Size = System::Drawing::Size(119, 16);
            this->lbl_vertical->TabIndex = 15;
            this->lbl_vertical->Text = L"величина сдвига";
            //
            // tb_vertical
            //
            this->tb_vertical->Location = System::Drawing::Point(804, 249);
            this->tb_vertical->Name = L"tb_vertical";
            this->tb_vertical->Size = System::Drawing::Size(100, 22);
            this->tb_vertical->TabIndex = 16;
            //
            // lbl_start
            //
            this->lbl_start->AutoSize = true;
            this->lbl_start->Location = System::Drawing::Point(801, 9);
            this->lbl_start->Name = L"lbl_start";
            this->lbl_start->Size = System::Drawing::Size(129, 16);
            this->lbl_start->TabIndex = 17;
            this->lbl_start->Text = L"Количество  точек";
            //
            // tb_start
            //
            this->tb_start->Location = System::Drawing::Point(801, 30);
            this->tb_start->Name = L"tb_start";
            this->tb_start->Size = System::Drawing::Size(100, 22);
            this->tb_start->TabIndex = 18;
            //
            // btn_start
            //
            this->btn_start->Location = System::Drawing::Point(678, 12);
            this->btn_start->Name = L"btn_start";
            this->btn_start->Size = System::Drawing::Size(106, 40);
            this->btn_start->TabIndex = 19;
            this->btn_start->Text = L"начать";
            this->btn_start->UseVisualStyleBackColor = true;
            this->btn_start->Click += gcnew System::EventHandler(this, &MyForm::btn_start_Click);
            //
            // btn_center
            //
            this->btn_center->Location = System::Drawing::Point(678, 279);
            this->btn_center->Name = L"btn_center";
            this->btn_center->Size = System::Drawing::Size(106, 58);
            this->btn_center->TabIndex = 20;
            this->btn_center->Text = L"Двигать относительно центра";
            this->btn_center->UseVisualStyleBackColor = true;
            this->btn_center->Click += gcnew System::EventHandler(this, &MyForm::btn_center_Click);
            //
            // btn_scale_gor
            //
            this->btn_scale_gor->Location = System::Drawing::Point(678, 343);
            this->btn_scale_gor->Name = L"btn_scale_gor";
            this->btn_scale_gor->Size = System::Drawing::Size(106, 62);
            this->btn_scale_gor->TabIndex = 21;
            this->btn_scale_gor->Text = L"Масштаб по горизонтали";
            this->btn_scale_gor->UseVisualStyleBackColor = true;
            this->btn_scale_gor->Click += gcnew System::EventHandler(this, &MyForm::btn_scale_gor_Click);
            //
            // btn_scale_vert
            //
            this->btn_scale_vert->Location = System::Drawing::Point(678, 411);
            this->btn_scale_vert->Name = L"btn_scale_vert";
            this->btn_scale_vert->Size = System::Drawing::Size(106, 44);
            this->btn_scale_vert->TabIndex = 22;
            this->btn_scale_vert->Text = L"Масштаб по вертикали";
            this->btn_scale_vert->UseVisualStyleBackColor = true;
            this->btn_scale_vert->Click += gcnew System::EventHandler(this, &MyForm::btn_scale_vert_Click);
            //
            // MyForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(995, 527);
            this->Controls->Add(this->btn_scale_vert);
            this->Controls->Add(this->btn_scale_gor);
            this->Controls->Add(this->btn_center);
            this->Controls->Add(this->btn_start);
            this->Controls->Add(this->tb_start);
            this->Controls->Add(this->lbl_start);
            this->Controls->Add(this->tb_vertical);
            this->Controls->Add(this->lbl_vertical);
            this->Controls->Add(this->tb_gorizontal);
            this->Controls->Add(this->lbl_gorizontal);
            this->Controls->Add(this->btn_vertical);
            this->Controls->Add(this->btn_gorizontal);
            this->Controls->Add(this->tb_scale);
            this->Controls->Add(this->lbl_scale);
            this->Controls->Add(this->btn_scale);
            this->Controls->Add(this->tb_rotate);
            this->Controls->Add(this->lbl_rotate);
            this->Controls->Add(this->btn_rotate_center);
            this->Controls->Add(this->btn_clear);
            this->Controls->Add(this->btn_many_coal);
            this->Controls->Add(this->lb_Point);
            this->Controls->Add(this->pb_for_clock);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_for_clock))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
        Brush^ b;
        Pen^ pn_contour, ^ pn_arrows;
        array<PointF>^ MyPoint, ^ realPoint;
        PointF center;
        array<float, 2>^ edit;
        int N, n = 0;
        void clear(Image^ img, Brush^ b) {
            Graphics^ gr = Graphics::FromImage(img);
            gr->FillRectangle(b, 0, 0, img->Width, img->Height);
        }

    private: System::Void btn_many_coal_Click(System::Object^ sender, System::EventArgs^ e) {
            clear(pb_for_clock->Image, b);
            Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
            gr->DrawPolygon(pn_arrows, MyPoint);
            pb_for_clock->Refresh();
        }
    private: System::Void btn_clear_Click(System::Object^ sender, System::EventArgs^ e) {
            clear(pb_for_clock->Image, b);
            pb_for_clock->Refresh();
            delete MyPoint;
            MyPoint = gcnew array<PointF>(4);
            n = 0;
            tb_gorizontal->Text = "";
            tb_rotate->Text = "";
            tb_scale->Text = "";
            tb_start->Text = "";
            tb_vertical->Text = "";
            N = 0;
            lb_Point->Items->Clear();
        }
        //перемножение матриц
        void multiply(array<float, 2>^ A, array<float, 2>^ B, array<float, 2>^ C) {
            int n = A->GetLength(0), m = B->GetLength(1), k = A->GetLength(1);
            assert(k == B->GetLength(0) && n == C->GetLength(0) && m == C->GetLength(1));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    C[i, j] = 0;
                    for (int p = 0; p < k; p++)
                        C[i, j] += A[i, p] * B[p, j];
                }
        }
        //единичная матрица
        void identity_mat(array<float, 2>^ M) {
            int n = M->GetLength(0), m = M->GetLength(1);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    M[i, j] = float(i == j);
        }
        //функция сдвига
        void move_mat(float dx, float dy, array<float, 2>^ T) {
            identity_mat(T);
            T[0, T->GetLength(1) - 1] = dx;
            T[1, T->GetLength(1) - 1] = dy;
        }
        //функция масштабирования
        void scale_mat(float kx, float ky, array<float, 2>^ S) {
            identity_mat(S);
            S[0, 0] = kx;
            S[1, 1] = ky;
        }
        //функция поворота
        void rotate_mat(float phi, array<float, 2>^ R) {
            identity_mat(R);
            R[0, 0] = cos(phi);
            R[1, 1] = cos(phi);
            R[0, 1] = sin(phi);
            R[1, 0] = -1 * R[0, 1];
        }

        PointF apply(PointF p, array<float, 2>^ M) {//перевод изначальных координат в реальные
            return PointF(p.X * M[0, 0] + p.Y * M[0, 1] + M[0, 2], p.X * M[1, 0] + p.Y * M[1, 1] + M[1, 2]);
        }

        void scale_mat(PointF c, float kx, float ky, array<float, 2>^ S) {
            scale_mat(kx, ky, S);
            PointF scaled_c = apply(c, S);
            S[0, S->GetLength(1) - 1] = c.X - scaled_c.X;
            S[1, S->GetLength(1) - 1] = c.Y - scaled_c.Y;
        }

        void rotate_mat(PointF c, float phi, array<float, 2>^ R) {
            rotate_mat(phi, R);
            PointF rot_c = apply(c, R);//зачем?
            R[0, R->GetLength(1) - 1] = c.X - rot_c.X;
            R[1, R->GetLength(1) - 1] = c.Y - rot_c.Y;
        }


        void typing(array<PointF>^ t) {
            String^ str;
            lb_Point->Items->Clear();
            for (int i = 0; i < n; i++) {
                str = Convert::ToString(MyPoint[i].X);
                str += ";";
                str += Convert::ToString(MyPoint[i].Y);
                lb_Point->Items->Add(str);
            }
        }

        PointF rotate(PointF p/*которую поворачиваем*/, PointF c/*вокруг которой поворачиваем*/, float phi) {
            return PointF(c.X + (p.X - c.X) * Math::Cos(phi) - (p.Y - c.Y) * Math::Sin(phi),
                          c.Y + (p.X - c.X) * Math::Sin(phi) + (p.Y - c.Y) * Math::Cos(phi));
        }
        void drawclock(Image^ img, Brush^ b,
                       Pen^ pn_contour, Pen^ pn_arrows,
                       PointF center, float r, float dash_len,
                       float h_len, float m_len, float s_len, DateTime time) {

            Graphics^ gr = Graphics::FromImage(img);
            gr->FillEllipse(b, center.X - r, center.Y - r, 2 * r, 2 * r);
            gr->DrawEllipse(pn_contour, center.X - r, center.Y - r, 2 * r, 2 * r);

            int n = 12;
            float phi = 0,
                    dphi = 2 * Math::PI / n;
            Point po(center.X, center.Y - r),
                    p1(po.X, po.Y + dash_len);

            for (int i = 0; i < n; i++) {
                PointF ps = rotate(po, center, phi + i * dphi);
                PointF pe = rotate(p1, center, phi + i * dphi);
                gr->DrawLine(pn_contour, ps, pe);
            }

            float s = 2 * Math::PI / 60 * time.Second,
                    m = 2 * Math::PI / 60 * time.Minute + s / 60,
                    h = 2 * Math::PI / 12 * time.Hour + m / 12;
            PointF hend = rotate(PointF(center.X, center.Y - h_len), center, h),
                    mend = rotate(PointF(center.X, center.Y - m_len), center, m),
                    send = rotate(PointF(center.X, center.Y - s_len), center, s);
            gr->DrawLine(pn_arrows, center, hend);
            gr->DrawLine(pn_arrows, center, mend);
            gr->DrawLine(pn_arrows, center, send);
        }


    private: System::Void pb_for_clock_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
            if (n < N) {
                MyPoint[n].X = Convert::ToInt32(e->Location.X);
                MyPoint[n].Y = Convert::ToInt32(e->Location.Y);
                n++;
                typing(MyPoint);
            }
            center.X = e->Location.X;
            center.Y = e->Location.Y;
        }

    private: System::Void btn_rotate_center_Click(System::Object^ sender, System::EventArgs^ e) {
            float phi = (-1) * Convert::ToDouble(tb_rotate->Text);
            array<float, 2>^ A = gcnew array<float, 2>(3, 3);
            array<float, 2>^ C = gcnew array<float, 2>(3, 3);

            /*move_mat(-center.X, -center.Y, A);
            multiply(A, edit, C);
            rotate_mat(phi, A);
            multiply(A, C, edit);
            move_mat(center.X, center.Y, A);*/
            rotate_mat(center, phi, A);

            multiply(A, edit, C);
            array<float, 2>::Copy(C, edit, C->Length);

            for (int i = 0; i < N; i++) {
                realPoint[i] = apply(MyPoint[i], edit);
            }
            Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
            clear(pb_for_clock->Image, b);
            gr->DrawPolygon(pn_arrows, realPoint);
            pb_for_clock->Refresh();
            typing(MyPoint);
        }
    private: System::Void btn_scale_Click(System::Object^ sender, System::EventArgs^ e) {
            float sc = Convert::ToDouble(tb_scale->Text);

            array<float, 2>^ A = gcnew array<float, 2>(3, 3);
            array<float, 2>^ C = gcnew array<float, 2>(3, 3);

            scale_mat(center, sc, sc, A);

            multiply(A, edit, C);
            array<float, 2>::Copy(C, edit, C->Length);

            for (int i = 0; i < N; i++) {
                realPoint[i] = apply(MyPoint[i], edit);
            }

            Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
            clear(pb_for_clock->Image, b);
            gr->DrawPolygon(pn_arrows, realPoint);
            pb_for_clock->Refresh();
            typing(MyPoint);
        }

    private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) {
            N = Convert::ToInt32(tb_start->Text);
            if (N < 3) {
                MessageBox::Show("Количество точек должно быть больше двух", "Кажется, Вы чайник",
                                 MessageBoxButtons::OK);
                tb_start->Text = "";
            }
            else {
                MyPoint = gcnew array<PointF>(N);
                realPoint = gcnew array<PointF>(N);
                identity_mat(edit);
            }
        }
    private: System::Void btn_gorizontal_Click(System::Object^ sender, System::EventArgs^ e) {
            int dx = Convert::ToInt32(tb_gorizontal->Text);
            array<float, 2>^ A = gcnew array<float, 2>(3, 3);
            array<float, 2>^ C = gcnew array<float, 2>(3, 3);
            move_mat(dx, 0, A);
            multiply(A, edit, C);
            array<float, 2>::Copy(C, edit, C->Length);

            for (int i = 0; i < N; i++) {
                realPoint[i] = apply(MyPoint[i], edit);
            }
            Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
            clear(pb_for_clock->Image, b);
            gr->DrawPolygon(pn_arrows, realPoint);
            pb_for_clock->Refresh();
            typing(MyPoint);
        }
    private: System::Void btn_vertical_Click(System::Object^ sender, System::EventArgs^ e) {
            int dy = Convert::ToInt32(tb_vertical->Text);
            array<float, 2>^ A = gcnew array<float, 2>(3, 3);
            array<float, 2>^ C = gcnew array<float, 2>(3, 3);
            move_mat(0, dy, A);
            multiply(A, edit, C);
            array<float, 2>::Copy(C, edit, C->Length);

            for (int i = 0; i < N; i++) {
                realPoint[i] = apply(MyPoint[i], edit);
            }
            Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
            clear(pb_for_clock->Image, b);
            gr->DrawPolygon(pn_arrows, realPoint);
            pb_for_clock->Refresh();
            typing(MyPoint);
        }
    private: System::Void btn_center_Click(System::Object^ sender, System::EventArgs^ e) {
            center.X = 0, center.Y = 0;
        }

    private: System::Void btn_scale_gor_Click(System::Object^ sender, System::EventArgs^ e) {
            float sc = Convert::ToDouble(tb_scale->Text);

            array<float, 2>^ A = gcnew array<float, 2>(3, 3);
            array<float, 2>^ C = gcnew array<float, 2>(3, 3);

            scale_mat(center, sc, 1, A);

            multiply(A, edit, C);
            array<float, 2>::Copy(C, edit, C->Length);

            for (int i = 0; i < N; i++) {
                realPoint[i] = apply(MyPoint[i], edit);
            }
            Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
            clear(pb_for_clock->Image, b);
            gr->DrawPolygon(pn_arrows, realPoint);
            pb_for_clock->Refresh();
            typing(MyPoint);
        }
    private: System::Void btn_scale_vert_Click(System::Object^ sender, System::EventArgs^ e) {
            float sc = Convert::ToDouble(tb_scale->Text);

            array<float, 2>^ A = gcnew array<float, 2>(3, 3);
            array<float, 2>^ C = gcnew array<float, 2>(3, 3);
#pragma once
#include "windows.h"
#include "cassert"
#include "cmath"

            namespace labaaftergraphics {

                using namespace System;
                using namespace System::ComponentModel;
                using namespace System::Collections;
                using namespace System::Windows::Forms;
                using namespace System::Data;
                using namespace System::Drawing;

                /// <summary>
                /// Сводка для MyForm
                /// </summary>
                public ref class MyForm : public System::Windows::Forms::Form
                {
                public:
                    MyForm(void)
                    {
                        InitializeComponent();
                        pb_for_clock->Image = gcnew Bitmap(pb_for_clock->Width, pb_for_clock->Height);
                        b = gcnew SolidBrush(Color::White);
                        pn_contour = gcnew Pen(Color::Black, 3);
                        pn_arrows = gcnew Pen(Color::Coral, 3);
                        edit = gcnew array<float, 2>(3, 3);
                        identity_mat(edit);
                        center.X = 0, center.Y = 0;
                        //
                        //TODO: добавьте код конструктора
                        //
                    }

                protected:
                    /// <summary>
                    /// Освободить все используемые ресурсы.
                    /// </summary>
                    ~MyForm()
                    {
                        if (components)
                        {
                            delete components;
                        }
                        delete MyPoint;
                    }

                private: System::Windows::Forms::PictureBox^ pb_for_clock;
                private: System::Windows::Forms::ListBox^ lb_Point;
                private: System::Windows::Forms::Button^ btn_many_coal;
                private: System::Windows::Forms::Button^ btn_clear;
                private: System::Windows::Forms::Button^ btn_rotate_center;

                private: System::Windows::Forms::Label^ lbl_rotate;
                private: System::Windows::Forms::TextBox^ tb_rotate;
                private: System::Windows::Forms::Button^ btn_scale;
                private: System::Windows::Forms::Label^ lbl_scale;
                private: System::Windows::Forms::TextBox^ tb_scale;
                private: System::Windows::Forms::Button^ btn_gorizontal;
                private: System::Windows::Forms::Button^ btn_vertical;
                private: System::Windows::Forms::Label^ lbl_gorizontal;
                private: System::Windows::Forms::TextBox^ tb_gorizontal;
                private: System::Windows::Forms::Label^ lbl_vertical;
                private: System::Windows::Forms::TextBox^ tb_vertical;
                private: System::Windows::Forms::Label^ lbl_start;
                private: System::Windows::Forms::TextBox^ tb_start;
                private: System::Windows::Forms::Button^ btn_start;
                private: System::Windows::Forms::Button^ btn_center;
                private: System::Windows::Forms::Button^ btn_scale_gor;

                private: System::Windows::Forms::Button^ btn_scale_vert;






                protected:


                private:
                    /// <summary>
                    /// Обязательная переменная конструктора.
                    /// </summary>
                    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
                    /// <summary>
                    /// Требуемый метод для поддержки конструктора — не изменяйте
                    /// содержимое этого метода с помощью редактора кода.
                    /// </summary>
                    void InitializeComponent(void)
                    {
                        this->pb_for_clock = (gcnew System::Windows::Forms::PictureBox());
                        this->lb_Point = (gcnew System::Windows::Forms::ListBox());
                        this->btn_many_coal = (gcnew System::Windows::Forms::Button());
                        this->btn_clear = (gcnew System::Windows::Forms::Button());
                        this->btn_rotate_center = (gcnew System::Windows::Forms::Button());
                        this->lbl_rotate = (gcnew System::Windows::Forms::Label());
                        this->tb_rotate = (gcnew System::Windows::Forms::TextBox());
                        this->btn_scale = (gcnew System::Windows::Forms::Button());
                        this->lbl_scale = (gcnew System::Windows::Forms::Label());
                        this->tb_scale = (gcnew System::Windows::Forms::TextBox());
                        this->btn_gorizontal = (gcnew System::Windows::Forms::Button());
                        this->btn_vertical = (gcnew System::Windows::Forms::Button());
                        this->lbl_gorizontal = (gcnew System::Windows::Forms::Label());
                        this->tb_gorizontal = (gcnew System::Windows::Forms::TextBox());
                        this->lbl_vertical = (gcnew System::Windows::Forms::Label());
                        this->tb_vertical = (gcnew System::Windows::Forms::TextBox());
                        this->lbl_start = (gcnew System::Windows::Forms::Label());
                        this->tb_start = (gcnew System::Windows::Forms::TextBox());
                        this->btn_start = (gcnew System::Windows::Forms::Button());
                        this->btn_center = (gcnew System::Windows::Forms::Button());
                        this->btn_scale_gor = (gcnew System::Windows::Forms::Button());
                        this->btn_scale_vert = (gcnew System::Windows::Forms::Button());
                        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_for_clock))->BeginInit();
                        this->SuspendLayout();
                        //
                        // pb_for_clock
                        //
                        this->pb_for_clock->Location = System::Drawing::Point(12, 12);
                        this->pb_for_clock->Name = L"pb_for_clock";
                        this->pb_for_clock->Size = System::Drawing::Size(500, 500);
                        this->pb_for_clock->TabIndex = 1;
                        this->pb_for_clock->TabStop = false;
                        this->pb_for_clock->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pb_for_clock_MouseDown);
                        //
                        // lb_Point
                        //
                        this->lb_Point->FormattingEnabled = true;
                        this->lb_Point->ItemHeight = 16;
                        this->lb_Point->Location = System::Drawing::Point(542, 12);
                        this->lb_Point->Name = L"lb_Point";
                        this->lb_Point->Size = System::Drawing::Size(120, 196);
                        this->lb_Point->TabIndex = 2;
                        //
                        // btn_many_coal
                        //
                        this->btn_many_coal->Location = System::Drawing::Point(524, 357);
                        this->btn_many_coal->Name = L"btn_many_coal";
                        this->btn_many_coal->Size = System::Drawing::Size(122, 73);
                        this->btn_many_coal->TabIndex = 3;
                        this->btn_many_coal->Text = L"построить многоугольник";
                        this->btn_many_coal->UseVisualStyleBackColor = true;
                        this->btn_many_coal->Click += gcnew System::EventHandler(this, &MyForm::btn_many_coal_Click);
                        //
                        // btn_clear
                        //
                        this->btn_clear->Location = System::Drawing::Point(524, 436);
                        this->btn_clear->Name = L"btn_clear";
                        this->btn_clear->Size = System::Drawing::Size(122, 35);
                        this->btn_clear->TabIndex = 4;
                        this->btn_clear->Text = L"Очистить";
                        this->btn_clear->UseVisualStyleBackColor = true;
                        this->btn_clear->Click += gcnew System::EventHandler(this, &MyForm::btn_clear_Click);
                        //
                        // btn_rotate_center
                        //
                        this->btn_rotate_center->Location = System::Drawing::Point(678, 58);
                        this->btn_rotate_center->Name = L"btn_rotate_center";
                        this->btn_rotate_center->Size = System::Drawing::Size(106, 52);
                        this->btn_rotate_center->TabIndex = 5;
                        this->btn_rotate_center->Text = L"Повернуть на угол";
                        this->btn_rotate_center->UseVisualStyleBackColor = true;
                        this->btn_rotate_center->Click += gcnew System::EventHandler(this, &MyForm::btn_rotate_center_Click);
                        //
                        // lbl_rotate
                        //
                        this->lbl_rotate->AutoSize = true;
                        this->lbl_rotate->Location = System::Drawing::Point(801, 59);
                        this->lbl_rotate->Name = L"lbl_rotate";
                        this->lbl_rotate->Size = System::Drawing::Size(103, 16);
                        this->lbl_rotate->TabIndex = 6;
                        this->lbl_rotate->Text = L"угол поворота";
                        //
                        // tb_rotate
                        //
                        this->tb_rotate->Location = System::Drawing::Point(801, 78);
                        this->tb_rotate->Name = L"tb_rotate";
                        this->tb_rotate->Size = System::Drawing::Size(100, 22);
                        this->tb_rotate->TabIndex = 7;
                        //
                        // btn_scale
                        //
                        this->btn_scale->Location = System::Drawing::Point(678, 116);
                        this->btn_scale->Name = L"btn_scale";
                        this->btn_scale->Size = System::Drawing::Size(106, 55);
                        this->btn_scale->TabIndex = 8;
                        this->btn_scale->Text = L"Изменить масштаб";
                        this->btn_scale->UseVisualStyleBackColor = true;
                        this->btn_scale->Click += gcnew System::EventHandler(this, &MyForm::btn_scale_Click);
                        //
                        // lbl_scale
                        //
                        this->lbl_scale->AutoSize = true;
                        this->lbl_scale->Location = System::Drawing::Point(801, 116);
                        this->lbl_scale->Name = L"lbl_scale";
                        this->lbl_scale->Size = System::Drawing::Size(167, 16);
                        this->lbl_scale->TabIndex = 9;
                        this->lbl_scale->Text = L"Коэффициент масштаба";
                        //
                        // tb_scale
                        //
                        this->tb_scale->Location = System::Drawing::Point(801, 135);
                        this->tb_scale->Name = L"tb_scale";
                        this->tb_scale->Size = System::Drawing::Size(100, 22);
                        this->tb_scale->TabIndex = 10;
                        //
                        // btn_gorizontal
                        //
                        this->btn_gorizontal->Location = System::Drawing::Point(678, 177);
                        this->btn_gorizontal->Name = L"btn_gorizontal";
                        this->btn_gorizontal->Size = System::Drawing::Size(106, 45);
                        this->btn_gorizontal->TabIndex = 11;
                        this->btn_gorizontal->Text = L"сдвинуть по горизонтали";
                        this->btn_gorizontal->UseVisualStyleBackColor = true;
                        this->btn_gorizontal->Click += gcnew System::EventHandler(this, &MyForm::btn_gorizontal_Click);
                        //
                        // btn_vertical
                        //
                        this->btn_vertical->Location = System::Drawing::Point(678, 229);
                        this->btn_vertical->Name = L"btn_vertical";
                        this->btn_vertical->Size = System::Drawing::Size(106, 43);
                        this->btn_vertical->TabIndex = 12;
                        this->btn_vertical->Text = L"сдвинуть по вертикали";
                        this->btn_vertical->UseVisualStyleBackColor = true;
                        this->btn_vertical->Click += gcnew System::EventHandler(this, &MyForm::btn_vertical_Click);
                        //
                        // lbl_gorizontal
                        //
                        this->lbl_gorizontal->AutoSize = true;
                        this->lbl_gorizontal->Location = System::Drawing::Point(798, 177);
                        this->lbl_gorizontal->Name = L"lbl_gorizontal";
                        this->lbl_gorizontal->Size = System::Drawing::Size(95, 16);
                        this->lbl_gorizontal->TabIndex = 13;
                        this->lbl_gorizontal->Text = L"длина сдвига";
                        //
                        // tb_gorizontal
                        //
                        this->tb_gorizontal->Location = System::Drawing::Point(801, 200);
                        this->tb_gorizontal->Name = L"tb_gorizontal";
                        this->tb_gorizontal->Size = System::Drawing::Size(100, 22);
                        this->tb_gorizontal->TabIndex = 14;
                        //
                        // lbl_vertical
                        //
                        this->lbl_vertical->AutoSize = true;
                        this->lbl_vertical->Location = System::Drawing::Point(801, 229);
                        this->lbl_vertical->Name = L"lbl_vertical";
                        this->lbl_vertical->Size = System::Drawing::Size(119, 16);
                        this->lbl_vertical->TabIndex = 15;
                        this->lbl_vertical->Text = L"величина сдвига";
                        //
                        // tb_vertical
                        //
                        this->tb_vertical->Location = System::Drawing::Point(804, 249);
                        this->tb_vertical->Name = L"tb_vertical";
                        this->tb_vertical->Size = System::Drawing::Size(100, 22);
                        this->tb_vertical->TabIndex = 16;
                        //
                        // lbl_start
                        //
                        this->lbl_start->AutoSize = true;
                        this->lbl_start->Location = System::Drawing::Point(801, 9);
                        this->lbl_start->Name = L"lbl_start";
                        this->lbl_start->Size = System::Drawing::Size(129, 16);
                        this->lbl_start->TabIndex = 17;
                        this->lbl_start->Text = L"Количество  точек";
                        //
                        // tb_start
                        //
                        this->tb_start->Location = System::Drawing::Point(801, 30);
                        this->tb_start->Name = L"tb_start";
                        this->tb_start->Size = System::Drawing::Size(100, 22);
                        this->tb_start->TabIndex = 18;
                        //
                        // btn_start
                        //
                        this->btn_start->Location = System::Drawing::Point(678, 12);
                        this->btn_start->Name = L"btn_start";
                        this->btn_start->Size = System::Drawing::Size(106, 40);
                        this->btn_start->TabIndex = 19;
                        this->btn_start->Text = L"начать";
                        this->btn_start->UseVisualStyleBackColor = true;
                        this->btn_start->Click += gcnew System::EventHandler(this, &MyForm::btn_start_Click);
                        //
                        // btn_center
                        //
                        this->btn_center->Location = System::Drawing::Point(678, 279);
                        this->btn_center->Name = L"btn_center";
                        this->btn_center->Size = System::Drawing::Size(106, 58);
                        this->btn_center->TabIndex = 20;
                        this->btn_center->Text = L"Двигать относительно центра";
                        this->btn_center->UseVisualStyleBackColor = true;
                        this->btn_center->Click += gcnew System::EventHandler(this, &MyForm::btn_center_Click);
                        //
                        // btn_scale_gor
                        //
                        this->btn_scale_gor->Location = System::Drawing::Point(678, 343);
                        this->btn_scale_gor->Name = L"btn_scale_gor";
                        this->btn_scale_gor->Size = System::Drawing::Size(106, 62);
                        this->btn_scale_gor->TabIndex = 21;
                        this->btn_scale_gor->Text = L"Масштаб по горизонтали";
                        this->btn_scale_gor->UseVisualStyleBackColor = true;
                        this->btn_scale_gor->Click += gcnew System::EventHandler(this, &MyForm::btn_scale_gor_Click);
                        //
                        // btn_scale_vert
                        //
                        this->btn_scale_vert->Location = System::Drawing::Point(678, 411);
                        this->btn_scale_vert->Name = L"btn_scale_vert";
                        this->btn_scale_vert->Size = System::Drawing::Size(106, 44);
                        this->btn_scale_vert->TabIndex = 22;
                        this->btn_scale_vert->Text = L"Масштаб по вертикали";
                        this->btn_scale_vert->UseVisualStyleBackColor = true;
                        this->btn_scale_vert->Click += gcnew System::EventHandler(this, &MyForm::btn_scale_vert_Click);
                        //
                        // MyForm
                        //
                        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
                        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
                        this->ClientSize = System::Drawing::Size(995, 527);
                        this->Controls->Add(this->btn_scale_vert);
                        this->Controls->Add(this->btn_scale_gor);
                        this->Controls->Add(this->btn_center);
                        this->Controls->Add(this->btn_start);
                        this->Controls->Add(this->tb_start);
                        this->Controls->Add(this->lbl_start);
                        this->Controls->Add(this->tb_vertical);
                        this->Controls->Add(this->lbl_vertical);
                        this->Controls->Add(this->tb_gorizontal);
                        this->Controls->Add(this->lbl_gorizontal);
                        this->Controls->Add(this->btn_vertical);
                        this->Controls->Add(this->btn_gorizontal);
                        this->Controls->Add(this->tb_scale);
                        this->Controls->Add(this->lbl_scale);
                        this->Controls->Add(this->btn_scale);
                        this->Controls->Add(this->tb_rotate);
                        this->Controls->Add(this->lbl_rotate);
                        this->Controls->Add(this->btn_rotate_center);
                        this->Controls->Add(this->btn_clear);
                        this->Controls->Add(this->btn_many_coal);
                        this->Controls->Add(this->lb_Point);
                        this->Controls->Add(this->pb_for_clock);
                        this->Name = L"MyForm";
                        this->Text = L"MyForm";
                        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_for_clock))->EndInit();
                        this->ResumeLayout(false);
                        this->PerformLayout();

                    }
#pragma endregion
                    Brush^ b;
                    Pen^ pn_contour, ^ pn_arrows;
                    array<PointF>^ MyPoint, ^ realPoint;
                    PointF center;
                    array<float, 2>^ edit;
                    int N, n = 0;
                    void clear(Image^ img, Brush^ b) {
                        Graphics^ gr = Graphics::FromImage(img);
                        gr->FillRectangle(b, 0, 0, img->Width, img->Height);
                    }

                private: System::Void btn_many_coal_Click(System::Object^ sender, System::EventArgs^ e) {
                        clear(pb_for_clock->Image, b);
                        Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
                        gr->DrawPolygon(pn_arrows, MyPoint);
                        pb_for_clock->Refresh();
                    }
                private: System::Void btn_clear_Click(System::Object^ sender, System::EventArgs^ e) {
                        clear(pb_for_clock->Image, b);
                        pb_for_clock->Refresh();
                        delete MyPoint;
                        MyPoint = gcnew array<PointF>(4);
                        n = 0;
                        tb_gorizontal->Text = "";
                        tb_rotate->Text = "";
                        tb_scale->Text = "";
                        tb_start->Text = "";
                        tb_vertical->Text = "";
                        N = 0;
                        lb_Point->Items->Clear();
                    }
                    //перемножение матриц
                    void multiply(array<float, 2>^ A, array<float, 2>^ B, array<float, 2>^ C) {
                        int n = A->GetLength(0), m = B->GetLength(1), k = A->GetLength(1);
                        assert(k == B->GetLength(0) && n == C->GetLength(0) && m == C->GetLength(1));
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < m; j++) {
                                C[i, j] = 0;
                                for (int p = 0; p < k; p++)
                                    C[i, j] += A[i, p] * B[p, j];
                            }
                    }
                    //единичная матрица
                    void identity_mat(array<float, 2>^ M) {
                        int n = M->GetLength(0), m = M->GetLength(1);
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < m; j++)
                                M[i, j] = float(i == j);
                    }
                    //функция сдвига
                    void move_mat(float dx, float dy, array<float, 2>^ T) {
                        identity_mat(T);
                        T[0, T->GetLength(1) - 1] = dx;
                        T[1, T->GetLength(1) - 1] = dy;
                    }
                    //функция масштабирования
                    void scale_mat(float kx, float ky, array<float, 2>^ S) {
                        identity_mat(S);
                        S[0, 0] = kx;
                        S[1, 1] = ky;
                    }
                    //функция поворота
                    void rotate_mat(float phi, array<float, 2>^ R) {
                        identity_mat(R);
                        R[0, 0] = cos(phi);
                        R[1, 1] = cos(phi);
                        R[0, 1] = sin(phi);
                        R[1, 0] = -1 * R[0, 1];
                    }

                    PointF apply(PointF p, array<float, 2>^ M) {//перевод изначальных координат в реальные
                        return PointF(p.X * M[0, 0] + p.Y * M[0, 1] + M[0, 2], p.X * M[1, 0] + p.Y * M[1, 1] + M[1, 2]);
                    }

                    void scale_mat(PointF c, float kx, float ky, array<float, 2>^ S) {
                        scale_mat(kx, ky, S);
                        PointF scaled_c = apply(c, S);
                        S[0, S->GetLength(1) - 1] = c.X - scaled_c.X;
                        S[1, S->GetLength(1) - 1] = c.Y - scaled_c.Y;
                    }

                    void rotate_mat(PointF c, float phi, array<float, 2>^ R) {
                        rotate_mat(phi, R);
                        PointF rot_c = apply(c, R);//зачем?
                        R[0, R->GetLength(1) - 1] = c.X - rot_c.X;
                        R[1, R->GetLength(1) - 1] = c.Y - rot_c.Y;
                    }


                    void typing(array<PointF>^ t) {
                        String^ str;
                        lb_Point->Items->Clear();
                        for (int i = 0; i < n; i++) {
                            str = Convert::ToString(MyPoint[i].X);
                            str += ";";
                            str += Convert::ToString(MyPoint[i].Y);
                            lb_Point->Items->Add(str);
                        }
                    }

                    PointF rotate(PointF p/*которую поворачиваем*/, PointF c/*вокруг которой поворачиваем*/, float phi) {
                        return PointF(c.X + (p.X - c.X) * Math::Cos(phi) - (p.Y - c.Y) * Math::Sin(phi),
                                      c.Y + (p.X - c.X) * Math::Sin(phi) + (p.Y - c.Y) * Math::Cos(phi));
                    }
                    void drawclock(Image^ img, Brush^ b,
                                   Pen^ pn_contour, Pen^ pn_arrows,
                                   PointF center, float r, float dash_len,
                                   float h_len, float m_len, float s_len, DateTime time) {

                        Graphics^ gr = Graphics::FromImage(img);
                        gr->FillEllipse(b, center.X - r, center.Y - r, 2 * r, 2 * r);
                        gr->DrawEllipse(pn_contour, center.X - r, center.Y - r, 2 * r, 2 * r);

                        int n = 12;
                        float phi = 0,
                                dphi = 2 * Math::PI / n;
                        Point po(center.X, center.Y - r),
                                p1(po.X, po.Y + dash_len);

                        for (int i = 0; i < n; i++) {
                            PointF ps = rotate(po, center, phi + i * dphi);
                            PointF pe = rotate(p1, center, phi + i * dphi);
                            gr->DrawLine(pn_contour, ps, pe);
                        }

                        float s = 2 * Math::PI / 60 * time.Second,
                                m = 2 * Math::PI / 60 * time.Minute + s / 60,
                                h = 2 * Math::PI / 12 * time.Hour + m / 12;
                        PointF hend = rotate(PointF(center.X, center.Y - h_len), center, h),
                                mend = rotate(PointF(center.X, center.Y - m_len), center, m),
                                send = rotate(PointF(center.X, center.Y - s_len), center, s);
                        gr->DrawLine(pn_arrows, center, hend);
                        gr->DrawLine(pn_arrows, center, mend);
                        gr->DrawLine(pn_arrows, center, send);
                    }


                private: System::Void pb_for_clock_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
                        if (n < N) {
                            MyPoint[n].X = Convert::ToInt32(e->Location.X);
                            MyPoint[n].Y = Convert::ToInt32(e->Location.Y);
                            n++;
                            typing(MyPoint);
                        }
                        center.X = e->Location.X;
                        center.Y = e->Location.Y;
                    }

                private: System::Void btn_rotate_center_Click(System::Object^ sender, System::EventArgs^ e) {
                        float phi = (-1) * Convert::ToDouble(tb_rotate->Text);
                        array<float, 2>^ A = gcnew array<float, 2>(3, 3);
                        array<float, 2>^ C = gcnew array<float, 2>(3, 3);

                        /*move_mat(-center.X, -center.Y, A);
                        multiply(A, edit, C);
                        rotate_mat(phi, A);
                        multiply(A, C, edit);
                        move_mat(center.X, center.Y, A);*/
                        rotate_mat(center, phi, A);

                        multiply(A, edit, C);
                        array<float, 2>::Copy(C, edit, C->Length);

                        for (int i = 0; i < N; i++) {
                            realPoint[i] = apply(MyPoint[i], edit);
                        }
                        Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
                        clear(pb_for_clock->Image, b);
                        gr->DrawPolygon(pn_arrows, realPoint);
                        pb_for_clock->Refresh();
                        typing(MyPoint);
                    }
                private: System::Void btn_scale_Click(System::Object^ sender, System::EventArgs^ e) {
                        float sc = Convert::ToDouble(tb_scale->Text);

                        array<float, 2>^ A = gcnew array<float, 2>(3, 3);
                        array<float, 2>^ C = gcnew array<float, 2>(3, 3);

                        scale_mat(center, sc, sc, A);

                        multiply(A, edit, C);
                        array<float, 2>::Copy(C, edit, C->Length);

                        for (int i = 0; i < N; i++) {
                            realPoint[i] = apply(MyPoint[i], edit);
                        }

                        Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
                        clear(pb_for_clock->Image, b);
                        gr->DrawPolygon(pn_arrows, realPoint);
                        pb_for_clock->Refresh();
                        typing(MyPoint);
                    }

                private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) {
                        N = Convert::ToInt32(tb_start->Text);
                        if (N < 3) {
                            MessageBox::Show("Количество точек должно быть больше двух", "Кажется, Вы чайник",
                                             MessageBoxButtons::OK);
                            tb_start->Text = "";
                        }
                        else {
                            MyPoint = gcnew array<PointF>(N);
                            realPoint = gcnew array<PointF>(N);
                            identity_mat(edit);
                        }
                    }
                private: System::Void btn_gorizontal_Click(System::Object^ sender, System::EventArgs^ e) {
                        int dx = Convert::ToInt32(tb_gorizontal->Text);
                        array<float, 2>^ A = gcnew array<float, 2>(3, 3);
                        array<float, 2>^ C = gcnew array<float, 2>(3, 3);
                        move_mat(dx, 0, A);
                        multiply(A, edit, C);
                        array<float, 2>::Copy(C, edit, C->Length);

                        for (int i = 0; i < N; i++) {
                            realPoint[i] = apply(MyPoint[i], edit);
                        }
                        Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
                        clear(pb_for_clock->Image, b);
                        gr->DrawPolygon(pn_arrows, realPoint);
                        pb_for_clock->Refresh();
                        typing(MyPoint);
                    }
                private: System::Void btn_vertical_Click(System::Object^ sender, System::EventArgs^ e) {
                        int dy = Convert::ToInt32(tb_vertical->Text);
                        array<float, 2>^ A = gcnew array<float, 2>(3, 3);
                        array<float, 2>^ C = gcnew array<float, 2>(3, 3);
                        move_mat(0, dy, A);
                        multiply(A, edit, C);
                        array<float, 2>::Copy(C, edit, C->Length);

                        for (int i = 0; i < N; i++) {
                            realPoint[i] = apply(MyPoint[i], edit);
                        }
                        Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
                        clear(pb_for_clock->Image, b);
                        gr->DrawPolygon(pn_arrows, realPoint);
                        pb_for_clock->Refresh();
                        typing(MyPoint);
                    }
                private: System::Void btn_center_Click(System::Object^ sender, System::EventArgs^ e) {
                        center.X = 0, center.Y = 0;
                    }

                private: System::Void btn_scale_gor_Click(System::Object^ sender, System::EventArgs^ e) {
                        float sc = Convert::ToDouble(tb_scale->Text);

                        array<float, 2>^ A = gcnew array<float, 2>(3, 3);
                        array<float, 2>^ C = gcnew array<float, 2>(3, 3);

                        scale_mat(center, sc, 1, A);

                        multiply(A, edit, C);
                        array<float, 2>::Copy(C, edit, C->Length);

                        for (int i = 0; i < N; i++) {
                            realPoint[i] = apply(MyPoint[i], edit);
                        }
                        Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
                        clear(pb_for_clock->Image, b);
                        gr->DrawPolygon(pn_arrows, realPoint);
                        pb_for_clock->Refresh();
                        typing(MyPoint);
                    }
                private: System::Void btn_scale_vert_Click(System::Object^ sender, System::EventArgs^ e) {
                        float sc = Convert::ToDouble(tb_scale->Text);

                        array<float, 2>^ A = gcnew array<float, 2>(3, 3);
                        array<float, 2>^ C = gcnew array<float, 2>(3, 3);

                        scale_mat(center, 1, sc, A);

                        multiply(A, edit, C);
                        array<float, 2>::Copy(C, edit, C->Length);

                        for (int i = 0; i < N; i++) {
                            realPoint[i] = apply(MyPoint[i], edit);
                        }
                        Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
                        clear(pb_for_clock->Image, b);
                        gr->DrawPolygon(pn_arrows, realPoint);
                        pb_for_clock->Refresh();
                        typing(MyPoint);
                    }


                };
            };
            scale_mat(center, 1, sc, A);

            multiply(A, edit, C);
            array<float, 2>::Copy(C, edit, C->Length);

            for (int i = 0; i < N; i++) {
                realPoint[i] = apply(MyPoint[i], edit);
            }
            Graphics^ gr = Graphics::FromImage(pb_for_clock->Image);
            clear(pb_for_clock->Image, b);
            gr->DrawPolygon(pn_arrows, realPoint);
            pb_for_clock->Refresh();
            typing(MyPoint);
        }


    };
};