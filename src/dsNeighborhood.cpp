//
//  dsNeighborhood.cpp
//  Dudley
//
//  Created by Sosolimited on 7/15/14.
//
//

#include "dsNeighborhood.h"

dsNeighborhood::dsNeighborhood(){
  polygon = NULL;
}

dsNeighborhood::~dsNeighborhood(){
  if (polygon != NULL)
    delete(polygon);
}

void dsNeighborhood::setName(string iName){
  name = iName;
}
string dsNeighborhood::getName(){
  return name;
}

void dsNeighborhood::addVertX(float iVertX){
  vertsX.push_back(iVertX);
}
vector<float> dsNeighborhood::getVertsX(){
  return vertsX;
}

void dsNeighborhood::addVertY(float iVertY){
  vertsY.push_back(iVertY);
}
vector<float> dsNeighborhood::getVertsY(){
  return vertsY;
}

void dsNeighborhood::addBounds(float iLeftBound, float iRightBound, float iBottomBound, float iTopBound){
  leftBound = iLeftBound;
  rightBound = iRightBound;
  bottomBound = iBottomBound;
  topBound = iTopBound;
  
  // Now that we have the bounds, calculate the centroid/center of the neighborhood.
  calculateCentroid();
}

float dsNeighborhood::getBound(string iBound){
  if (iBound == "left") { return leftBound; }
  else if (iBound == "right") { return rightBound; }
  else if (iBound == "bottom") { return bottomBound; }
  else if (iBound == "top") { return topBound; }
}

void dsNeighborhood::calculateCentroid(){
  if (leftBound && rightBound && bottomBound && topBound){
    centroid.x = (leftBound + rightBound)/2.0;
    centroid.y = (bottomBound + topBound)/2.0;
    centroid.z = 0;
  } else {
    ofLog() << "dsNeighborhood- ERROR : Cannot calculate centroid!";
  }
}

ofVec3f dsNeighborhood::getCentroid(){
  return centroid;
}

ofxPolygonObject* dsNeighborhood::getPolygon(){

  if (polygon == NULL) {
    ofLogNotice("polygon getting created of size " + ofToString(vertsX.size()));
    polygon = new ofxPolygonObject(vertsX.size());
    polygon->setDrawMode(OF_OUTLINE);
    
    for (int i = 0 ; i < vertsX.size() ; i ++) {
      polygon->setVertexPos(i, ofVec3f(vertsX[i], vertsY[i], 0));
    }
    
  } else {
    ofLogNotice("NO DATA MADE");

  }
  
  return polygon;
}

