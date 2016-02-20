#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>



// chandeg this file, power of a comment
int main(int argc, char *argv[]) {
    QApplication prog(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("How many chicken wings?");

    QSpinBox *spinner = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinner->setRange(0,100);
    slider->setRange(0,100);

    QObject::connect(spinner,SIGNAL(valueChanged(int)),
                     slider,SLOT(setValue(int)));

    QObject::connect(slider,SIGNAL(valueChanged(int)),
                     spinner,SLOT(setValue(int)));

    spinner->setValue(50);


    QHBoxLayout *layout = new QHBoxLayout();
     layout->addWidget(spinner);
    layout->addWidget(slider);

    mainWindow->setLayout(layout);
    mainWindow->show();

    return prog.exec();
}
