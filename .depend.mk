map.o: map.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h cccfiles/ccc_x11.h \
 map.h Square.h drawConstants.h
Square.o: Square.cc Square.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h drawFunctions.h drawConstants.h
towerDefense.o: towerDefense.cc cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h player.h map.h Square.h drawFunctions.h \
 drawConstants.h
player.o: player.cc player.h cccfiles/ccc_win.h cccfiles/ccc_shap.h \
 cccfiles/ccc_x11.h
drawFunctions.o: drawFunctions.cc drawFunctions.h cccfiles/ccc_win.h \
 cccfiles/ccc_shap.h cccfiles/ccc_x11.h drawConstants.h
drawConstants.o: drawConstants.cc
