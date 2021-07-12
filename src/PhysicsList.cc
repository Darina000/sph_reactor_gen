#include "PhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"
#include "G4EmLowEPPhysics.hh"
#include "G4EmLivermorePolarizedPhysics.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmDNAPhysics.hh"
#include "G4BraggIonModel.hh"

//#include "G4ElectronPhysics.hh"
#include "G4DecayPhysics.hh"


#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

//#include "HadronElasticPhysicsHP.hh"
#include "G4HadronPhysicsFTFP_BERT_HP.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4HadronPhysicsINCLXX.hh"
#include "G4IonPhysics.hh"
#include "G4IonINCLXXPhysics.hh"
#include "G4StoppingPhysics.hh"
//#include "GammaNuclearPhysics.hh"

#include "G4PenelopePhotoElectricModel.hh"
#include "G4RadioactiveDecayPhysics.hh"

#include "G4PenelopeComptonModel.hh";
#include "G4ComptonScattering.hh";
//#include "G4LowEnergyPhotoElectric.hh"
//#include "G4LowEnergyIonisation.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::PhysicsList()
: G4VModularPhysicsList(){
 // SetVerboseLevel(2);

  //RegisterPhysics(new G4DecayPhysics());
    
    //AddTransportation();
    
   // RegisterPhysics(new G4EmLivermorePhysics());
 //   RegisterPhysics( new G4EmPenelopePhysics() );
 //   RegisterPhysics( new G4OpticalPhysics() );
   // RegisterPhysics( new G4EmLivermorePolarizedPhysics() );
   // RegisterPhysics( new G4EmLowEPPhysics() );
    //RegisterPhysics( new G4EmStandardPhysics_option4() );
   RegisterPhysics( new G4EmStandardPhysics() );

 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::~PhysicsList()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::SetCuts()
{
  G4VUserPhysicsList::SetCuts();
    
    G4double lowlimit = 100*keV;
G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(lowlimit, 100.*GeV);

  //  SetCutValue(0.00000000000001 * mm,"gamma");
    SetCutValue(0.001 * mm,"e-");
    G4VUserPhysicsList::SetCutsWithDefault();
    //DumpCutValuesTable();
}


