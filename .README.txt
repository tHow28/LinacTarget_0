
///\file "B1/.README.txt"
///\brief Example B1 README page

/*! \page ExampleB1 Example B1

 This example simulates the impingement of an electron beam on a LINAC target. 
 Quantities measured include energy deposit in target, energy distribution in target, and
 the energy and angular distribution of the X-rays generated. 

\section B1_s1 GEOMETRY DEFINITION
	
   The geometry is constructed in the B1DetectorConstruction class.
   The setup consists of two cylindrical volumes placed directly next to each other, the
   front one being made of tungsten and the back made of copper. 

   The thickness, material, and shape of the target will be altered to perform analysis on 
   various target designs. 

	
\section B1_s2 PHYSICS LIST

   The particle's type and the physic processes which will be available
   in this example are set in the QBBC physics list. This physics list 
   requires data files for electromagnetic and hadronic processes.
   See more on installation of the datasets in
   <a href="http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides
                                         /InstallationGuide/html/ch03s03.html">
   Geant4 Installation Guide, Chapter 3.3: Note On Geant4 Datasets </a>.
   The following datasets: G4LEDATA, G4LEVELGAMMADATA, G4NEUTRONXSDATA,
   G4SAIDXSDATA and G4ENSDFSTATEDATA are mandatory for this example.
 
   In addition the build-in interactive command:
\verbatim
/process/(in)activate processName
\endverbatim
     allows to activate/inactivate the processes one by one.
     
\section B1_s3 ACTION INITALIZATION

   A newly introduced class, B1ActionInitialization, instantiates and registers 
   to Geant4 kernel all user action classes.

   While in sequential mode the action classes are instatiated just once,
   via invoking the method:
      B1ActionInitialization::Build() 
   in multi-threading mode the same method is invoked for each thread worker
   and so all user action classes are defined thread-local.

   A run action class is instantiated both thread-local 
   and global that's why its instance is created also in the method
      B1ActionInitialization::BuildForMaster() 
   which is invoked only in multi-threading mode.
     
\section B1_s4 PRIMARY GENERATOR

   The primary generator is defined in the B1PrimaryGeneratorAction class.
   There are no default settings applied to the particle generator, these 
   settings (such as energy, direction, distribution) are assigned using
   commands in the macro files or using /gps/ commands in the UI. 
   
\section B1_s5 DETECTOR RESPONSE

   This application uses Geant4 command-based scoring to obtain the distribution 
   of energy deposited throughout the volume of the target.
   
   The energy deposited is collected step by step for the tungsten and 
   the copper separately in B1SteppingAction and accumulated event by event in 
   B1EventAction.
   
   At end of event, the value acummulated in B1EventAction is added in B1RunAction
   and summed over the whole run (see B1EventAction::EndOfevent()).
   
   Total energy deposited in tungsten and copper is computed at 
   B1RunAction::EndOfRunAction(), and printed.

   The same process f using accumulables is used to sum the energy converted to X-rays 
   and printed at the end of the run. 
   
   G4Accumulable<G4double> type instead of G4double type is used for the B1RunAction
   data members in order to facilitate merging of the values accumulated on workers 
   to the master.  Currently the accumulables have to be registered to G4AccumulablesManager
   and G4AccumulablesManager::Merge() has to be called from the users code. This is planned
   to be further simplified with a closer integration of G4Accumulable classes in
   the Geant4 kernel next year.

   Ntuples are created and filled with information about the hits that occur in the tungsten
   and copper sensitive detectors. Another Ntuple is populated with the energy of X-rays
  (gammas) that are generated.

\section B1_s4 MACRO FILES

   The macro file run1.mac sets up the particle source to be a circular source of 6 MeV
   electrons. The electrons are fired at the tungsten side of the target normal to the 
   circular face. 

   The macro file run2.mac fires the same particle source at the target, and also includes 
   a scoring mesh to discretize the target and obtain the distribution of the energy 
   deposited in the target. 
    
