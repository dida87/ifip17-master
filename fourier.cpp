#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char ** argv){
//if argc >=2 alors argv[1] sinon 
//const char * filename = argc >= 2 ? argv[1] : "/home/dida/Desktop/mars.jpg";
Mat img;
img = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
if(!img.data){
	cout<<"Impossible de charger l'image\n"<<endl;
	return -1;
}
//Avec transformer de fourier il faut elargir l'image (expand)
Mat expend_img;
//getOptimalDFTSize => mutiplie la taille de l'image pour une meilleure performance
int m = getOptimalDFTSize(img.rows);
cout<<"Lignes image\n"<<m<<endl;
int n = getOptimalDFTSize(img.cols);
cout<<"Colonne image\n"<<n<<endl;
//ajout des 0 aux bordures de l'images
//copymakeBorder=>elargir les bordures de l'images(src, dst, top, bottom, left, right
copyMakeBorder(img, expend_img, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));
Mat planes[] = {Mat_<float>(expend_img), Mat::zeros(expend_img.size(), CV_32F)};
Mat complex_img;
//ajouter l'image elargir
merge(planes,2, complex_img);
dft(complex_img, complex_img);
split(complex_img, planes);
magnitude(planes[0], planes[1], planes[0]);
Mat magI = planes[0];
magI += Scalar::all(1);
log(magI, magI);
magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
//arranger les quadrants de l'image de fourier (l'origine au centre)
int cx = magI.cols / 2;
int cy = magI.rows / 2;
//top left 
Mat q0(magI, Rect(0, 0, cx, cy));
//top right
Mat q1(magI, Rect(cx, 0, cx, cy));
//bottom left
Mat q2(magI, Rect(0, cy, cx, cy));
//bottom right
Mat q3(magI, Rect(cx, cy, cx, cy));
//changer les quadrant
Mat tmp;
//swap les quadrants
q0.copyTo(tmp);
q3.copyTo(q0);
tmp.copyTo(q3);
//
q1.copyTo(tmp);
q2.copyTo(q1);
tmp.copyTo(q2);
//Normalisation
normalize(magI, magI, 0, 1, CV_MINMAX);
//afficher l'imge
imshow("Image en entree", img);
imshow("Spectrum magnitude",magI);
imwrite("spect.jpg", magI);
waitKey(0);
return 0;
}
