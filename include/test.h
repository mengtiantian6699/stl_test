typedef struct MessageHeader {
  uint8_t MessageType;      ///<消息类型
  uint64_t TimeStamp;       ///<时间戳
  uint32_t MessagerCounter; ///<消息计数器
  uint8_t SenderType;       ///<发送主体类型
  uint8_t ProtocolVersion;  ///<协议版本号
} MessageHeader;

typedef struct HMI_SEND_TO_CAR_TOPIC {
  MessageHeader header;
  uint8_t APASwitch;
  uint8_t HMI_APA_mode_select;
  uint8_t HMI_APA_ConfirmButton;
  uint8_t HMI_APA_popup_select_confirm;
  uint8_t HMI_APA_Function_Select;
  uint8_t HMI_APA_CP_Change;
  uint8_t NextToPark;
  uint8_t Setting_Change_Request;
  uint8_t Sgl_View_Sel;
  uint8_t CarMdlTrsprcySwtCmd;
  uint8_t MODSetRequest;
  uint8_t LaneCalActvtCmd;
  uint8_t LaneCalResetRequest;
  uint8_t FactoryCalRequest;
  uint8_t FactoryCalResult;
  uint8_t AutoAVM_Steering_SET;
  uint8_t AutoAVM_D_Range_SET;
  uint8_t TrackLineSET;
  uint8_t DistanceLineSET;
  uint8_t Suggest_APA_SET;
  uint8_t SelectParkSpotID;
  uint8_t SelectParkSpotType;
  uint8_t AVMDispReq;
  uint8_t DetVideoLost;
  uint8_t ScrnOpSts;
  uint16_t XLvl;
  uint16_t Ylvl;
  uint8_t APA_ParkingDir_Req;
} HMI_SEND_TO_CAR_TOPIC;

typedef struct HMI_SEND_TO_CAR_TOPIC_TEST {
  //   MessageHeader header;
  uint8_t APASwitch;
  uint8_t HMI_APA_mode_select;
  uint8_t HMI_APA_ConfirmButton;
  uint8_t HMI_APA_popup_select_confirm;
  uint8_t HMI_APA_Function_Select;
  uint8_t HMI_APA_CP_Change;
  uint8_t NextToPark;
  uint8_t Setting_Change_Request;
  uint8_t Sgl_View_Sel;
  uint8_t CarMdlTrsprcySwtCmd;
  uint8_t MODSetRequest;
  uint8_t LaneCalActvtCmd;
  uint8_t LaneCalResetRequest;
  uint8_t FactoryCalRequest;
  uint8_t FactoryCalResult;
  uint8_t AutoAVM_Steering_SET;
  uint8_t AutoAVM_D_Range_SET;
  uint8_t TrackLineSET;
  uint8_t DistanceLineSET;
  uint8_t Suggest_APA_SET;
  uint8_t SelectParkSpotID;
  uint8_t SelectParkSpotType;
  uint8_t AVMDispReq;
  uint8_t DetVideoLost;
  uint8_t ScrnOpSts;
  uint16_t XLvl;
  uint16_t Ylvl;
  uint8_t APA_ParkingDir_Req;
} HMI_SEND_TO_CAR_TOPIC_TEST;