
#pragma once

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QFileDialog>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect> 
#include <QGraphicsPixmapItem>
#include <QPainter>
#include "./ui_blur.h"

QImage blurImage(QImage source, int blurRadius);

class CallerBlur :public QWidget, public Ui::blur {
  Q_OBJECT
public:
  CallerBlur(QWidget* parent = nullptr) : QWidget(parent) {
	setupUi(this);
  }
public slots:
  void slotOpenButton();
  void slotSliderBlur(int value);
private:
  QString path;
};
