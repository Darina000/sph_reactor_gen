//
//  RunAction.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"

#include "Analysis.hh"
#include "EventAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4EmCalculator.hh"
#include "Randomize.hh"
#include <iomanip>

using namespace std;


RunAction::RunAction(DetectorConstruction* det, PrimaryGeneratorAction* kin)
 : G4UserRunAction(),fDetector(det), fPrimary(kin)
{
    auto analysisManager =  G4AnalysisManager::Instance();
   // analysisManager->SetVerboseLevel(1);
}

RunAction::~RunAction()
{
    Pt->out_number_electron();//выводим количесвто электронов в поколении
    
    //remove("/Users/darazemlanskaa/Documents/Geant4_pr/snow/reactor_2/run1.mac");
    Pt->print_in_mac();
    
    
    delete  G4AnalysisManager::Instance();
}


void RunAction::BeginOfRunAction(const G4Run* run)
{
    cout << "Begin Run" << G4endl;

    
}

void RunAction::EndOfRunAction(const G4Run* run){
    // Save histograms
    
   //  auto analysisManager =  G4AnalysisManager::Instance();
    cout << "End Run" << G4endl;

}

