open Bindings;
open CountryData;
open Icons;
open SharedStyle;

module Style = {
  let button =
    ReactDOM.Style.make(
      ~alignItems="center",
      ~backgroundColor=colorToHex(Light),
      ~border=
        "1.5px solid var(--light-border-control-alpha, rgba(0, 0, 0, 0.20))",
      ~borderRadius="3px",
      ~columnGap="6px",
      ~display="flex",
      ~height="26px",
      ~justifyContent="space-between",
      ~minWidth="144px",
      ~padding="4px 10px",
      (),
    );
  let divPad =
    ReactDOM.Style.make(
      ~maxWidth="150px",
      ~overflow="hidden",
      ~padding="4px",
      ~textOverflow="ellipsis",
      ~whiteSpace="nowrap",
      (),
    );
  let dropdown =
    ReactDOM.Style.make(
      ~fontFamily="Arial",
      ~fontSize="14px",
      ~height="429px",
      ~position="relative",
      ~width="230px",
      (),
    );
  let flag = ReactDOM.Style.make(~width="14px", ~height="14px", ());

  let icon = {
    ReactDOM.Style.make(~padding="3px", ());
  };

  let search = {
    ReactDOM.Style.make(~padding="6px", ~margin="5px 0px 0px 2px", ());
  };
};
module CustomStyle = {
  let customStyle = {
    control: props =>
      ReactDOMStyle.combine(
        props,
        ReactDOMStyle.make(
          ~borderBottomWidth="0px",
          ~borderColor=colorToHex(Grey),
          ~borderRadius="2px 2px 0px 0px",
          ~borderWidth="1.5px",
          ~display="flex",
          ~flexDirection="row-reverse",
          ~outlineColor="pink",
          ~padding="2px",
          ~width="100%",
          (),
        ),
      ),
    menu: props =>
      ReactDOMStyle.combine(
        props,
        ReactDOMStyle.make(~borderRadius="0px 0px 2px 2px", ()),
      ),
  };
  let customTheme = {
    colors: {
      primary: "initial",
      primary25: colorToHex(Hover),
      neutral50: colorToHex(Grey),
      neutral80: colorToHex(Dark),
    },
    spacing: {
      baseUnit: 2,
      controlHeight: 11,
    },
  };
};

module Option = {
  module Style = {
    let optionFlag = ReactDOM.Style.make(~width="8%", ~height="14px", ());

    let flagStyles =
      ReactDOM.Style.make(
        ~alignItems="center",
        ~backgroundClip="padding-box",
        ~backgroundColor="initial",
        ~display="flex",
        ~flexDirection="row",
        ~justifyContent="space-between",
        ~padding="0px 6px",
        (),
      );

    let hoverStyles =
      ReactDOM.Style.make(~backgroundColor=colorToHex(Hover), ());

    let hoverFlagStyles = ReactDOM.Style.combine(flagStyles, hoverStyles);
    let unknownNumber =
      ReactDOM.Style.make(~color=colorToHex(Dark), ~opacity="0.5", ());
  };

  [@react.component]
  let make = (~internalProps, ~data) => {
    let (isHovered, setIsHovered) = React.useState(() => false);

    <div
      style={isHovered ? Style.hoverFlagStyles : Style.flagStyles}
      onMouseOver={_ => setIsHovered(_ => true)}
      onMouseOut={_ => setIsHovered(_ => false)}>
      <span className={"fi fi-" ++ data.value} style=Style.optionFlag />
      <Option props=internalProps />
      <div style=Style.unknownNumber> {React.string("0")} </div>
    </div>;
  };
};

module Menu = {
  module Style = {
    let menu = {
      ReactDOM.Style.make(
        ~borderRadius="4px",
        ~marginTop="3px",
        ~marginLeft="1px",
        ~position="absolute",
        ~width="100%",
        ~zIndex="2",
        (),
      );
    };
  };
  [@react.component]
  let make = (~children) => {
    <div style=Style.menu> children </div>;
  };
};
module Blanket = {
  module Style = {
    let blanket = {
      ReactDOM.Style.make(
        ~bottom="0",
        ~left="0",
        ~position="fixed",
        ~right="0",
        ~top="0",
        ~zIndex="1",
        (),
      );
    };
  };
  [@react.component]
  let make = (~onClick) => {
    <div onClick style=Style.blanket />;
  };
};

module Dropdown = {
  [@react.component]
  let make = (~target, ~children, ~isOpen, ~onClose) => {
    <div style=Style.dropdown>
      target
      {isOpen ? <Menu> children </Menu> : React.null}
      {isOpen ? <Blanket onClick=onClose /> : React.null}
    </div>;
  };
};

[@react.component]
let make = () => {
  let (active, setActive) = React.useState(() => false);
  let (countries, setCountries) =
    React.useState(() => countryLoadState(None));
  let (selectedCountry, setSelectedCountry) =
    React.useState(() => {label: "Select A country", value: "xx"});
  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json => json |> decode |> resolve)
          |> then_(itemArray =>
               countryLoadState(Some(itemArray)) |> resolve
             )
          |> then_(array => setCountries(_ => array) |> resolve)
        );
      Some(() => ());
    },
    [||],
  );
  <Dropdown
    isOpen=active
    onClose={_ => setActive(_ => false)}
    target={
      <button onClick={_ => setActive(prev => !prev)} style=Style.button>
        <span className={"fi fi-" ++ selectedCountry.value} style=Style.flag />
        <div style=Style.divPad> {React.string(selectedCountry.label)} </div>
        <Arrow style=Style.icon />
      </button>
    }>
    {active
       ? <Select
           autoFocus=true
           backspaceRemovesValue=false
           closeMenuOnSelect=true
           components={
             dropdownIndicator: _ => <Search style=Style.search />,
             indicatorSeparator: false,
             option: ({data} as internalProps: Select.optionProps) =>
               <Option internalProps data />,
           }
           controlShouldRenderValue=false
           hideSelectedOptions=false
           isClearable=false
           menuIsOpen=true
           multi=false
           name="Country Selector"
           noOptionsMessage={_ => "Country Not Found!"}
           onChange={value => {
             setSelectedCountry(_ => value);
             setActive(_ => !active);
           }}
           options=countries
           placeholder="Search"
           styles=CustomStyle.customStyle
           tabSelectsValue=false
           theme=CustomStyle.customTheme
           value={selectedCountry.label}
         />
       : React.null}
  </Dropdown>;
};
