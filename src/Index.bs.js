// Generated by BUCKLESCRIPT VERSION 2.2.2, PLEASE EDIT WITH CARE
'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Chart$ReactTemplate = require("./Chart.bs.js");

var data = /* :: */[
  /* tuple */[
    0.0,
    0.0
  ],
  /* :: */[
    /* tuple */[
      1.0,
      1.0
    ],
    /* :: */[
      /* tuple */[
        2.0,
        3.0
      ],
      /* :: */[
        /* tuple */[
          3.0,
          7.0
        ],
        /* :: */[
          /* tuple */[
            4.0,
            4.0
          ],
          /* :: */[
            /* tuple */[
              5.0,
              -2.0
            ],
            /* [] */0
          ]
        ]
      ]
    ]
  ]
];

ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, Chart$ReactTemplate.make(400, 400, /* record */[
              /* top */10,
              /* right */10,
              /* bottom */10,
              /* left */10
            ], data, /* None */0, /* None */0, /* array */[])), "index");

exports.data = data;
/*  Not a pure module */
