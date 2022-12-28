QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AccountListWidgetItem.cpp \
    MintDialog.cpp \
    TokenListWidgetItem.cpp \
    TradeDialog.cpp \
    ProvideDialog.cpp \
    MetricsTable.cpp \
    WalletListWidgetItem.cpp \
    main.cpp \
    MainWindow.cpp \
    src/Protocols/CurvePool.cpp \
    src/Protocols/Protocols.cpp \
    src/Utilities/Account.cpp \
    src/Utilities/Operation.cpp \
    src/Utilities/PoolInterface.cpp \
    src/Utilities/Token.cpp \
    src/Utilities/TokensContainer.cpp \
    src/Playground.cpp

HEADERS += \
    AccountListWidgetItem.h \
    MainWindow.h \
    MetricsTable.h \
    MintDialog.h \
    TokenListWidgetItem.h \
    TradeDialog.h \
    ProvideDialog.h \
    MetricsTable.h \
    WalletListWidgetItem.h \
    src/Utilities/Utilities.hpp \
    src/Protocols/BalancerPool.hpp \
    src/Protocols/ConstantSum.hpp \
    src/Protocols/CurvePool.hpp \
    src/Protocols/Protocols.hpp \
    src/Protocols/UniswapV2Pool.hpp \
    src/Protocols/UniswapV3Pool.hpp \
    src/Playground.hpp

FORMS += \
    AccountListWidgetItem.ui \
    MainWindow.ui \
    MetricsTable.ui \
    MintDialog.ui \
    TokenListWidgetItem.ui \
    TradeDialog.ui \
    MetricsTable.ui \
    WalletListWidgetItem.ui \
    ProvideDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
