//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
//
/// \file B1TungstenSD.hh
/// \brief Definition of the B1TungstenSD class
//

#ifndef B1TungstenSD_h
#define B1TungstenSD_h 1

#include "G4VSensitiveDetector.hh"
#include "B1TungstenHit.hh"

class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

class B1TungstenSD : public G4VSensitiveDetector
{
public:
    B1TungstenSD(const G4String& name,
        const G4String& hitsCollectionName,
        G4int ntupleID);
    virtual ~B1TungstenSD();

    virtual void   Initialize(G4HCofThisEvent* hce);
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
    virtual void   EndOfEvent(G4HCofThisEvent* hce);

private:
    B1TungstenHitsCollection* fHitsCollection;
    G4int fNtupleId;
};

#endif

