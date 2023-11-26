[@mel.module "react-select"]
[@react.component]
module Select = {
  [@mel.module "react-select"] [@react.component]
  external make: (~multi: bool, ~value: Option.t('a)=?) => React.element =
    "default";
};
