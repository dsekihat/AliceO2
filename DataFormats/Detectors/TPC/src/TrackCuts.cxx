// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#include "FairLogger.h"

#include "DataFormatsTPC/TrackCuts.h"
#include "DataFormatsTPC/TrackTPC.h"

ClassImp(o2::tpc::TrackCuts);

using namespace o2::tpc;

TrackCuts::TrackCuts(float PMin, float PMax, float NClusMin) : mPMin(PMin),
                                                               mPMax(PMax),
                                                               mNClusMin(NClusMin)
{
}

//______________________________________________________________________________
bool TrackCuts::goodTrack(o2::tpc::TrackTPC const& track)
{
  const auto p = track.getP();
  const auto nclusters = track.getNClusterReferences();

  if (p > mPMax) {
    return false;
  }
  if (p < mPMin) {
    return false;
  }
  if (nclusters < mNClusMin) {
    return false;
  }
  return true;
}
