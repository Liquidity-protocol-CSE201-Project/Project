QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    src/Utilities/Account.cpp\
    src/Utilities/FirstSimulation.cpp \
    src/Utilities/Initializer.cpp\
    src/Utilities/Operation.cpp\
    src/Utilities/PoolInterface.cpp\
    src/Utilities/Token.cpp\
    #src/Testing/AccountTest.cpp\
    #src/Testing/TokenTest.cpp\
    #src/Testing/BalancerPoolTest.cpp\
    #src/Testing/ConstantSumTest.cpp\
    #src/Testing/OperationTest.cpp\
    #src/Testing/PoolInterfaceTest.cpp\
    src/Testing/UniswapV2PoolTest.cpp\
    src/Utilities/UniswapV2PoolSimulation.cpp

HEADERS += \
    MainWindow.h \
    src/Utilities/FirstSimulation.hpp \
    src/Utilities/UniswapV2PoolSimulation.hpp \
    src/Utilities/Utilities.hpp \
    src/Protocols/BalancerPool.hpp\
    src/Protocols/ConstantSum.hpp\
    src/Protocols/UniswapV2Pool.hpp\
    src/Protocols/UniswapV3Pool.hpp\
    src/Protocols/UniswapV2Pool.hpp\

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
