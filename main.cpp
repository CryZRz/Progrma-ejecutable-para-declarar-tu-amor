#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

void moveWindow(Fl_Widget *widget, void *data){
    Fl_Window *window = widget->window();

    int x = rand() % 740;
    int y = rand() % 680;

    window->position(x, y);
}

void showNewWindow(Fl_Widget *, void *)
{
    Fl_Window *window = new Fl_Window(400, 100, "felicidades");
    Fl_Box *box = new Fl_Box(50, 2, 300, 100, "Felicidades ahora somos novios :)");
    box->labelsize(18);

    window->end(); 
    window->show();  
}

int main(int argc, char **argv){
    
    srand(time(nullptr));

    Fl_Window *window = new Fl_Window(320,180, "Tkm");

    Fl_Box *box = new Fl_Box(10, 10, 300, 100, "¿Quieres ser mi novia?");
    box->labelsize(18);

    Fl_Button *button1 = new Fl_Button(70,80,50,50, "Si");
    Fl_Button *button2 = new Fl_Button(200,80,50,50, "No");
    button1->callback((Fl_Callback*)showNewWindow);
    button2->callback((Fl_Callback*)moveWindow);

    window->add(button1);
    window->add(button2);
    window->end();
    window->show(argc, argv);

    return Fl::run();
}
