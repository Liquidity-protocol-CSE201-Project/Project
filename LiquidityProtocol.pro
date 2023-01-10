QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AccountListWidgetItem.cpp \
    ChangeModeDialog.cpp \
    ExistingPoolProvisionDialog.cpp \
    MarketInfo.cpp \
    MintDialog.cpp \
    NewPoolProvisionDialog.cpp \
    PoolGraphItem.cpp \
    PoolListWidgetItem.cpp \
    ProvideDialog.cpp \
    SimulationPlayground.cpp \
    TokenListWidgetItem.cpp \
    TradeDialog.cpp \
    WalletListWidgetItem.cpp \
    WithdrawDialog.cpp \
    main.cpp \
    MainWindow.cpp \
    qcustomplot.cpp \
    src/Utilities/Account.cpp \
    src/Utilities/Operation.cpp \
    src/Utilities/PoolInterface.cpp \
    src/Utilities/Token.cpp \
    src/Utilities/TokensContainer.cpp \
    src/Protocols/CurvePool.cpp \
    src/Protocols/Protocols.cpp \
    src/Playground.cpp \
    src/Market/Infrastructure/Market.cpp \
    src/Market/Infrastructure/CommunityActor.cpp

HEADERS += \
    AccountListWidgetItem.h \
    ChangeModeDialog.h \
    ExistingPoolProvisionDialog.h \
    MainWindow.h \
    MarketInfo.h \
    MintDialog.h \
    NewPoolProvisionDialog.h \
    PoolGraphItem.h \
    PoolListWidgetItem.h \
    ProvideDialog.h \
    SimulationPlayground.h \
    TokenListWidgetItem.h \
    TradeDialog.h \
    WalletListWidgetItem.h \
    qcustomplot.h \
    WithdrawDialog.h \
    src/Utilities/Utilities.hpp \
    src/Protocols/BalancerPool.hpp \
    src/Protocols/ConstantSum.hpp \
    src/Protocols/CurvePool.hpp \
    src/Protocols/Protocols.hpp \
    src/Protocols/UniswapV2Pool.hpp \
    src/Protocols/UniswapV3Pool.hpp \
    src/Playground.hpp \
    src/Market/Infrastructure/Market.hpp \
    src/Market/Infrastructure/CommunityActor.hpp

FORMS += \
    AccountListWidgetItem.ui \
    ChangeModeDialog.ui \
    ExistingPoolProvisionDialog.ui \
    MainWindow.ui \
    MarketInfo.ui \
    MintDialog.ui \
    NewPoolProvisionDialog.ui \
    PoolGraphItem.ui \
    PoolListWidgetItem.ui \
    ProvideDialog.ui \
    SimulationPlayground.ui \
    TokenListWidgetItem.ui \
    TradeDialog.ui \
    WalletListWidgetItem.ui \
    WithdrawDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
