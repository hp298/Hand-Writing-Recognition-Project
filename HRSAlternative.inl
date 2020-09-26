// classification
inline Image HRSAlternative::classify( const Image& img )
{
  // vars
  //Vector<Image> vec = m_vec;
  Vector<Image> imgVec;
  Vector<size_t> posVec;
  Image curImg;
  int votes[10];
  for( size_t i = 0; i < 10; i++) // set all to 0
    votes[i] = 0;
  int label;
  int k = m_k;
  
  
  // find k closest images
  for( size_t i = 0; i < m_k; i++) {
    // finds closest Euclidian Image 
    curImg = m_vec.find_closest_alt( img);
    imgVec.push_back( curImg );
    posVec.push_back( m_vec.m_altVar );
    m_vec[m_vec.m_altVar] = m_empty; 
    
    // adds the label to an array
    label = curImg.get_label() - '0';
    votes[label]++;
    if ( votes[label] > ( ( k / 2) + 1 ) ) {
      char winner = '0' + label;
      Image correct;
      correct.set_label( winner );
      return correct;
    }
  }

  
  for( size_t i = 0; i < imgVec.size(); i++ ) {
    m_vec[posVec[i]] = imgVec[i];
  }
  
  // pre-sets
  char winner = '0';
  int  winNum = votes[0];
  
  // find the largest vote
  for( size_t i = 0; i < 10; i++ ) {
    if ( winNum < votes[i] ) {
      winNum = votes[i];
      // int to ascii
      winner = '0' + i;
    }
  }
  
  // make image with the 'winning' label and return
  Image correct;
  correct.set_label( winner );
  return correct;
}
