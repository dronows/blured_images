// blured.cpp: определяет точку входа для приложения.
//

#include "blured.h"


QImage blurImage(QImage source, int blurRadius) {
  if (source.isNull()) return QImage();
  QGraphicsScene scene;
  QGraphicsPixmapItem item;
  item.setPixmap(QPixmap::fromImage(source));

  auto* blur = new QGraphicsBlurEffect;
  blur->setBlurRadius(blurRadius);
  item.setGraphicsEffect(blur);
  scene.addItem(&item);
  QImage result(source.size(), QImage::Format_ARGB32);
  result.fill(Qt::transparent);
  QPainter painter(&result);
  scene.render(&painter, QRectF(),
	QRectF(0, 0, source.width(), source.height()));
  return result;
}
//=======================================================

void CallerBlur::slotOpenButton() {
  path = QFileDialog::getOpenFileName(nullptr, "Open image",
	"./images", " jpg files(*.jpg)");
  QPixmap pix;
  pix.load(path);
  imageLabel->resize(pix.size());
  imageLabel->setPixmap(pix);
}
//-----------------------------------------------------
void CallerBlur::slotSliderBlur(int value) {
  imageLabel->setPixmap(QPixmap::fromImage(blurImage(QImage(path), value).scaled(
	           imageLabel->width(),
	           imageLabel->height(),
	           Qt::KeepAspectRatio)));
}