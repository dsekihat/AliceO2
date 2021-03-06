# Copyright 2019-2020 CERN and copyright holders of ALICE O2.
# See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
# All rights not expressly granted are reserved.
#
# This software is distributed under the terms of the GNU General Public
# License v3 (GPL Version 3), copied verbatim in the file "COPYING".
#
# In applying this license CERN does not waive the privileges and immunities
# granted to it by virtue of its status as an Intergovernmental Organization
# or submit itself to any jurisdiction.

o2_add_library(AnalysisCore
               SOURCES  src/CorrelationContainer.cxx
                        src/TrackSelection.cxx
                        src/TriggerAliases.cxx
                        src/HFConfigurables.cxx
               PUBLIC_LINK_LIBRARIES O2::Framework O2::AnalysisDataModel)

o2_target_root_dictionary(AnalysisCore
              HEADERS include/AnalysisCore/CorrelationContainer.h
                      include/AnalysisCore/TrackSelection.h
                      include/AnalysisCore/TrackSelectionDefaults.h
                      include/AnalysisCore/TriggerAliases.h
                      include/AnalysisCore/MC.h
                      include/AnalysisCore/HFConfigurables.h
              LINKDEF src/AnalysisCoreLinkDef.h)

o2_add_executable(merger
              COMPONENT_NAME aod
              SOURCES src/AODMerger.cxx
              PUBLIC_LINK_LIBRARIES ROOT::Hist ROOT::Core ROOT::Net)

if(FastJet_FOUND)
o2_add_library(AnalysisJets
               SOURCES  src/JetFinder.cxx
               PUBLIC_LINK_LIBRARIES O2::AnalysisCore FastJet::FastJet FastJet::Contrib)

o2_target_root_dictionary(AnalysisJets
              HEADERS include/AnalysisCore/JetFinder.h
              LINKDEF src/AnalysisJetsLinkDef.h)
endif()
