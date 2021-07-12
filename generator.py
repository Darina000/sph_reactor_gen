import xml.etree.ElementTree as ET
from string import Template
import os
import shutil
import subprocess
from multiprocessing import Pool
#PROGRAMM_GEANT4_PATH = ROOT_PATH + '../cmake-build-debug/'
# materials = ["G4_Ca", "G4_Fe","G4_GLASS_PLATE", "G4_WATER"]
# energy = [30, 50, 100, 150, 200, 300, 400, 500]

# raduis = [200, 500]


    
    
    
#def runSimulations(runPath):
#    print(runPath)
#    os.chdir(PROGRAMM_GEANT4_PATH)
    #shutil.copy('geant4-satellite.exe', runPath)
   # os.chdir(runPath)
   # p = subprocess.Popen(runPath + '/geant4-satellite.exe -d -g ./gdml/default.gdml -i ./mac/init.mac -gps ./gps/gps.mac', shell=True)
   # p.wait()
 #   os.remove(runPath + '/geant4-satellite.exe')
  #  return 0
def fun():
    currPath = os.getcwd()
    print(currPath)
    cmd = 'make'
    os.system(cmd)
    cmd = './prak'
    os.system(cmd)
    #return 0
        
    
def main():
    open('/home/npm/daria_modelling/reactror_sphere/generation_electron/reactor_2/src/._DetectorConstruction.cc', 'w').close() #удалить файлы мака
    open('/home/npm/daria_modelling/reactror_sphere/generation_electron/reactor_2/src/._PrimaryGeneratorAction.cc', 'w').close()
    open('/home/npm/daria_modelling/reactror_sphere/generation_electron/reactor_2/._run1.mac', 'w').close()
    open('/home/npm/daria_modelling/reactror_sphere/generation_electron/build/._pokolenia.txt', 'w').close()
    open('/home/npm/daria_modelling/reactror_sphere/generation_electron/build/._generator.txt', 'w').close()
    open('/home/npm/daria_modelling/reactror_sphere/generation_electron/build/run1.mac', 'w').close()
    f = open('/home/npm/daria_modelling/reactror_sphere/generation_electron/reactor_2/run1.mac', 'w')
    f.write("/run/beamOn 100" + '\n')
    f.close()
    path = "/home/npm/daria_modelling/reactror_sphere/generation_electron/reactor_2/run1.mac"
    while (os.path.getsize(path)) != 0 and (os.path.getsize(path)) < 20000000 :
        fun()
    
    
    #cmd = 'exit'
    #print(currPath)
     #   return 0
     
    #g = open('/home/npm/daria_modelling/reactror_sphere/generation_electron/build/pokolenia.txt', 'a')
   # g.write("#запустила в точке-320" + '\n')
   # g.write("#Field 200, R = 320м, запустила 100, 5MeV e- :")
   # g.close()
     
    
    
    
if __name__ == "__main__":
    main()
