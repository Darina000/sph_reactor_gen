
/// \file electromagnetic/TestEm18/src/StackingAction.cc
/// \brief Implementation of the StackingAction class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "StackingAction.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "PrimaryGeneratorAction.hh"


#include "G4Event.hh"
#include "G4VProcess.hh"

#include "G4ParticleTypes.hh"
#include "G4ios.hh"

#include "DetectorConstruction.hh"
#include "EventAction.hh"
#include "G4PhysicalConstants.hh"
#include "RunAction.hh"

#include "G4Event.hh"
#include "G4VProcess.hh"

#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include"PhysicsList.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "globals.hh"

#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include <time.h>
#include "G4EventManager.hh"
#include "G4Trajectory.hh"
#include "G4VHitsCollection.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>
#include "G4RunManager.hh"
#include "G4Run.hh"
#include <G4ParticleGunMessenger.hh>
#include <G4ParticleGun.hh>

#include "Analysis.hh"

#include "G4EmCalculator.hh"

#include "Randomize.hh"
#include <iomanip>

using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StackingAction::StackingAction(EventAction* EA)
:G4UserStackingAction(),  fEventAction(EA)
{
   // fKillSecondary  = false;
   // fParticle       = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StackingAction::~StackingAction()
{
  ///delete fStackMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ClassificationOfNewTrack
StackingAction::ClassifyNewTrack(const G4Track* aTrack)
{
   
    
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
   
    
    G4ThreeVector direction = aTrack->GetMomentumDirection();
    G4ThreeVector position =  aTrack -> GetPosition();
    G4double energy = aTrack->GetKineticEnergy();
    

    G4int trackID  = aTrack->GetTrackID();
    G4int parentID = aTrack->GetParentID();
    G4String name = aTrack->GetDefinition()->GetParticleName();
    
    cout << name << " trackID " << trackID << " parentID " <<  parentID<< G4endl;
    
    
    if (name == "gamma"){ //сохраняем номер трека гаммы
        fEventAction->fRunAct()->Pt->save_gamma(trackID);
        cout << name << " saved gamma id"<< endl;
    }
    
    //сохраняем парметры электронов
    for(auto i : fEventAction->fRunAct()->Pt->return_tarck_gamma() ){
        if(name == "e-" && i == parentID){
            Electron_o a(direction, position, energy/CLHEP::keV);
            fEventAction->fRunAct()->Pt->save_elect_param(a);
            
            cout << "BORN FROM GAMMA" << G4endl;
            
            return fKill;
        }
            
    }
     
    /*
    if (name == "gamma"){ //сохраняем номер трека гаммы
        fEventAction->fRunAct()->Pt->save_gamma(trackID);
        
        std::cout << name << " trackID: " << trackID << " energy " <<  energy/CLHEP::keV  << std::endl;
        //cout << "BORN GAMMA" << G4endl;
        
        
    }
    
    //сохраняем парметры электронов
    for(auto i : fEventAction->fRunAct()->Pt->return_tarck_gamma() ){
        if((name == "e-") && (i==trackID)){
            Electron_o a(direction, position, energy);
            fEventAction->fRunAct()->Pt->save_elect_param(a);
            
            //std::cout << name << " trackId "<< trackID <<" parentID " << parentID << " energy " <<  energy/CLHEP::keV  << std::endl;
            cout << "BORN FROM GAMMA" << G4endl;
            return fKill; //убиваем до сл поколения
        }
            
    }
     */
  //  G4double energy = aTrack->GetKineticEnergy();
    
   return fUrgent;
 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
