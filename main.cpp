#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

Mat roi(Mat src)
{
    //Create corner points
    Point Corners[1][6];
    Corners[0][0] = Point(0,240);
    Corners[0][1] = Point(0,160);
    Corners[0][2] = Point(100,90);
    Corners[0][3] = Point(200,90);
    Corners[0][4] = Point(320,160);
    Corners[0][5] = Point(320,240);

    //Create list of points
    const Point* corner_list[1] = { Corners[0] };

    //Setting for fill poly
    int num_points = 6;
    int num_polygons = 1;
    int line_type = 8;

    // Tao mask giong src nhung mau` den
    Mat mask = Mat::zeros(src.rows, src.cols, src.type());
    fillPoly( mask, corner_list, &num_points, num_polygons, Scalar( 255, 255, 255 ),  src.type());



    Mat result;
    bitwise_and(src,mask,result);
    return result;
}

int main(int argc, char *argv[])
{
    Mat img;
    // doc hinh
    img = imread("BienBao.png", 1);
    // kiem tra doc duoc hinh chua?
    if(img.empty())
       return -1;

    // create polygon from vertices

    Mat TestFunction = roi(img);



    //Mat Result_black = Mat::zeros(img.rows, img.cols, img.type());
    //bitwise_and(img, mask, Result_black, mask);

    namedWindow( "Roi Function", CV_WINDOW_AUTOSIZE );
    imshow("Roi Function", TestFunction);
    waitKey(0);
    return 0;
}



