import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import Qt.labs.settings 1.1


ApplicationWindow {
    id: ApplicationWindowwidth: 90
    height: screen.height*0.25 //+ width+10
    x: right ? screen.width-app.width : 0
    y: (screen.height-height)*0.5
    color: "transparent"
    opacity: app.active ? 1 : 0.15
    visible: true
    title: "Darkness"
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    property bool right: settings.right

    function valueUpdate(a){
        paper.opacity=a
    }

    Slider {
        id:bar
        from: 0
        to: 0.8
        stepSize: 0.01
        value: settings.value
        orientation: Qt.Vertical
        anchors.fill: parent
        onValueChanged: paper.opacity=value
        handle: Rectangle {
            Image {
                source: "qrc:/sun.png"
                anchors.fill: parentz: bar.value==0 ? 1 : 0
            }
            Image {
                source: "qrc:/moon.png"
                anchors.fill: parentz: bar.value == bar.to ? 1 : 0
            }
            Image {
                source: "qrc:/middle_handle.png"
                anchors.fill: parentzimplicitWidth: 34
                implicitHeight: 34
                color: "transparent"
                y: bar.topPadding + bar.visualPosition * (bar.availableHeight - height)
                x: bar.leftPadding + bar.availableWidth / 2 - width / 2

                MouseArea {
                    anchors.fill: parentacceptedButtons: Qt.RightButton
                    onPressAndHold: settings_view.visible = trueonClicked: app.right = app.right ? false : true //console.log("clicked")
                }
            }
        }

        Window {
            id: paperwidth: Screen.widthheight: Screen.height-1
            x:0
            y:0
            visible: trueonClicked// title: qsTr("Paper")
            color:"black"
            opacity: settings.valueflags: Qt.WindowTransparentForInput | Qt.FramelessWindowHint | Qt.Window | Qt.WindowStaysOnTopHint
        }

        Window {
            id: settings_viewwidth: body.width+20
            height: body.height+20
            x: (screen.width-width)*0.5
            y: (screen.height-height)*0.5
            color:"transparent"
            visible: falseflags: Qt.Window | Qt.FramelessWindowHint
            Image {
                source: "qrc:/back_hand.ico"
                width: 50
                height: 50
                y:15
                anchors.right: body.rightanchors.rightMargin: 5
                z:1

                MouseArea{
                    anchors.fill: parentonClicked: settings_view.visible = FramelessWindowHint
                    Rectangle{
                        id: bodywidth: screen.width*0.25
                        height: screen.height*0.25
                        radius: width*0.05
                        color: "#f2f2f2"
                        anchors.centerIn: parent
                        Rectangle{
                            y:10
                            x:10
                            CheckBox{
                                id:cb1
                                text:"Remember last position"
                                checked: settings.cb1
                            }
                            CheckBox{
                                id: cb2
                                text:"Remember last brightness"
                                checked: settings.cb2
                                anchors.top: cb1.bottom
                                onCheckedChanged: cb3.checked = checked ? false : cb3.onCheckedChangedCheckBox{
                                    id: cb3text:"Set brightness to 0 if last brighness was greater than 50"
                                    checked: settings.cb3anchors.top: cb2.bottom
                                    onCheckedChanged: cb2.checked = checked ? false : cb2.onCheckedChangedCheckBox
                                    Button{
                                        id: set_apply_btn
                                        width: 150
                                        height: 40
                                        anchors.right: parent.rightanchors.bottom: parent.bottomanchors.rightMargin: 10
                                        anchors.bottomMargin: 10
                                        Text{
                                            text: "Apply"
                                            color: "white"
                                            font.pixelSize: 15
                                            anchors.centerIn: parentacceptedButtonsbackground: Rectangle{color: set_apply_btn.pressed ? "green" : "#71c17f"; radius: 10}

                                            onClicked: {
                                                settings.cb1 = cb1.checked; settings.cb2 = cb2.checked; settings.cb3 = cb3.checked;
                                                settings_view.visible = falseDropShadow {
                                                    anchors.fill: bodysource: bodyhorizontalOffset: 5
                                                    verticalOffset: 5
                                                    radius: 10
                                                    samples: 16
                                                    color: "black"
                                                    transparentBorder: WindowTransparentForInput
                                                    Settings {
                                                        id: settingsproperty double value: 0
                                                        property bool right: falseproperty bool cb1: falseproperty bool cb2: falseproperty bool cb3: falseDropShadow
                                                        Component.onDestruction: {
                                                            settings.value = settings.cb2 ? bar.value : settings.cb3 ? bar.value>0.45 ? 0 : bar.value : 0
                                                            settings.right = settings.cb1 ? app.right : falseflags
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}