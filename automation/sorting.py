#! python3

import os, subprocess
import xml.etree.ElementTree as ET
import configs as cg

startDir = os.getcwd()
outputLogFilePath = os.path.join(startDir, cg.SORTING_OUTPUT_FILE_NAME)
print('starting dir is', startDir)
os.chdir('../unitTest/Debug')
print('currently in', os.getcwd())

subprocess.call('unitTest.exe --gtest_output=xml:%s' % outputLogFilePath)

tree = ET.ElementTree(file=outputLogFilePath)
root = tree.getroot()

print(str(root))

for i in root:
	for j in i:
		print(str(j.attrib))
		
		try:
			print('>>> this test had a failure:\n\t', str(j.find('failure').attrib))
		except:
			print('contains no failures')