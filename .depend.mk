tower.o: tower.cc tower.h type.h Square.h cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h drawFunctions.h drawConstants.h
EnemyUnit.o: EnemyUnit.cc EnemyUnit.h type.h tower.h Square.h \
 cccfiles/ccc_win.h cccfiles/ccc_shap.h cccfiles/ccc_x11.h \
 drawConstants.h
map.o: map.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h cccfiles/ccc_x11.h \
 tower.h type.h Square.h map.h path.h wave.h EnemyUnit.h drawConstants.h
Square.o: Square.cc Square.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h drawFunctions.h drawConstants.h
towerDefense.o: towerDefense.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h type.h tower.h Square.h path.h map.h wave.h \
 EnemyUnit.h constructionBox.h category.h player.h drawConstants.h \
 drawFunctions.h button.h towerButton.h attributeBox.h systemUpdater.h \
 gameMaps.h
path.o: path.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h cccfiles/ccc_x11.h \
 path.h
player.o: player.cc player.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h category.h tower.h type.h Square.h
type.o: type.cc type.h
attributeBox.o: attributeBox.cc attributeBox.h cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h category.h player.h tower.h \
 type.h Square.h drawFunctions.h drawConstants.h
category.o: category.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h category.h
drawFunctions.o: drawFunctions.cc drawFunctions.h cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h drawConstants.h
systemUpdater.o: systemUpdater.cc systemUpdater.h map.h Square.h \
 cccfiles/ccc_win.h cccfiles/ccc_shap.h cccfiles/ccc_x11.h path.h wave.h \
 EnemyUnit.h type.h tower.h attributeBox.h category.h player.h \
 drawFunctions.h drawConstants.h
button.o: button.cc button.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h drawConstants.h drawFunctions.h
towerButton.o: towerButton.cc towerButton.h button.h cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h drawConstants.h drawFunctions.h \
 tower.h type.h Square.h
constructionBox.o: constructionBox.cc cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h constructionBox.h category.h \
 player.h tower.h type.h Square.h drawConstants.h drawFunctions.h \
 button.h towerButton.h
wave.o: wave.cc wave.h EnemyUnit.h type.h tower.h Square.h \
 cccfiles/ccc_win.h cccfiles/ccc_shap.h cccfiles/ccc_x11.h
drawConstants.o: drawConstants.cc
gameMaps.o: gameMaps.cc gameMaps.h map.h Square.h cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h path.h wave.h EnemyUnit.h type.h \
 tower.h drawConstants.h
