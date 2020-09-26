//========================================================================
// hrs-alternative-directed-test.cc
//========================================================================
// Directed test cases for HRSAlternative.

#include <iostream>
#include "Image.h"
#include "Vector.h"
#include "HRSAlternative.h"
#include "mnist-utils.h"
#include "utst.h"

//------------------------------------------------------------------------
// Inputs
//------------------------------------------------------------------------

#include "digits.dat"

// The data included is as follows:
//
//     Digit    | Label
//     ---------+-------
//     digit0   | 5
//     digit1   | 3
//     digit2   | 2
//     digit3   | 1
//     digit4   | 1
//     digit5   | 6
//     digit6   | 5
//     digit7   | 8
//     digit8   | 9
//     digit9   | 7
//     digit10  | 0
//     digit11  | 7
//     digit12  | 4
//     digit13  | 0
//

//------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------

const std::string mnsit_dir = "/classes/ece2400/mnist/";
const unsigned int ncols    = 28;
const unsigned int nrows    = 28;
const unsigned int img_size = nrows * ncols;

//------------------------------------------------------------------------
// test_case_1_tiny_accuracy
//------------------------------------------------------------------------

void test_case_1_tiny_accuracy()
{
  std::printf( "\n%s\n", __func__ );

  const int training_size = 10;
  const int testing_size  = 10;
  
  // Read the training images

  Vector<Image> v_train;

  std::string image_path = mnsit_dir + "training-images-tiny.bin";
  std::string label_path = mnsit_dir + "training-labels-tiny.bin";

  read_labeled_images( image_path, label_path, v_train, training_size );

  // Read the testing images

  Vector<Image> v_test;

  image_path = mnsit_dir + "testing-images-tiny.bin";
  label_path = mnsit_dir + "testing-labels-tiny.bin";

  read_labeled_images( image_path, label_path, v_test, testing_size );

  // Train and classify

  HRSAlternative clf;

  double accuracy = train_and_classify( clf, v_train, v_test );
  std::cout << "Accuracy: " << accuracy << std::endl;

  // Accuracy should be...

  double expected_accuracy = 0.2;

  UTST_ASSERT_TRUE( accuracy > expected_accuracy );
}

//------------------------------------------------------------------------
// test_case_2_small_accuracy
//------------------------------------------------------------------------

void test_case_2_small_accuracy()
{
  std::printf( "\n%s\n", __func__ );

  const int training_size = 600;
  const int testing_size  = 100;

  // Read the training images

  Vector<Image> v_train;

  std::string image_path = mnsit_dir + "training-images-small.bin";
  std::string label_path = mnsit_dir + "training-labels-small.bin";

  read_labeled_images( image_path, label_path, v_train, training_size );

  // Read the testing images

  Vector<Image> v_test;

  image_path = mnsit_dir + "testing-images-small.bin";
  label_path = mnsit_dir + "testing-labels-small.bin";

  read_labeled_images( image_path, label_path, v_test, testing_size );

  // Train and classify

  HRSAlternative clf;

  double accuracy = train_and_classify( clf, v_train, v_test );
  std::cout << "Accuracy: " << accuracy << std::endl;

  // Accuracy should be...

  double expected_accuracy = 0.70;

  UTST_ASSERT_TRUE( accuracy >=  expected_accuracy );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1  ) ) test_case_1_tiny_accuracy();
  if ( ( __n == 0 ) || ( __n == 2  ) ) test_case_2_small_accuracy();

  return 0;
}
