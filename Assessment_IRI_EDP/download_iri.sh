#!/bin/bash
# Download and untar iri2016 files and and other supporting files
# from iri web page:
#STRING="You downloading iri2016 files from https://irimodel.org/IRI-2016/ page"
# print variable on a screen
#echo $STRING
#STRING="------ Please wait !---------"
#echo $STRING
#STRING= "------  Downloading 00_iri_tar file ------"
#echo $STRING
wget https://irimodel.org/IRI-2016/00_iri.tar

#STRING= "------  Extracting files from 00_iri_tar file ------"
#echo $STRING
tar -xvf 00_iri.tar

#STRING= "------  Downloading indices files ------"
#echo $STRING
wget  http://irimodel.org/indices/ig_rz.dat
wget  http://irimodel.org/indices/apf107.dat
#STRING= "------  Downloading COMMON_FILES ------"
#echo $STRING
wget  http://irimodel.org/COMMON_FILES/00_ccir-ursi.tar
#STRING= "------  Extracting files from 00_ccir-ursi.tar file ------"
#echo $STRING
tar -xvf 00_ccir-ursi.tar
#STRING = "------Done!------"
#echo $STRING
ls
