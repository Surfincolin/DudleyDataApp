//
//  dsCitizensData.h
//  Dudley
//
//  Created by Sosolimited on 7/11/14.
//
//

#pragma once

#include "ofMain.h"
#include "ofxJSONElement.h"
#include "ofxGeoJSON.h"

#include "Poco/LocalDateTime.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormat.h"

struct event{
  int id;
//  Poco::LocalDateTime time;
  string time;
  string status;
  float lat;
  float lon;
  string neighborhood;
  string category;
};

class dsCitizensData{

public:
  dsCitizensData(string url);
  ~dsCitizensData();

  void fetchNewestJson();
  void fetchGeoJson();
  ofxGeoJSON getGeoJson();
  
//  updateSubscribers()
//  addEventSubscriber()
  
private:

  string jsonUrl;                 // Contains the Open311 JSON query string originally passed to this class.
  std::vector<event> events;      // Contains the Open311 data transformed into objects.
  ofxJSONElement jsonResults;     // Contains the raw Open311 data
  ofxGeoJSON geojsonBoston;       // Contains the raw GeoJSON data of Boston.
  
//  std::vector<event*> neighborhoods;
//  std::vector<event*> categories;
//  std::vector<...*> eventSuscribers;
  
};