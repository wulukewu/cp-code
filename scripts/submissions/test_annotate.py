#!/usr/bin/env python3
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from annotate import LUKE_BANNER, MARKER, header, uva_number, without_header_bytes


class AnnotationTests(unittest.TestCase):
    def sample_submission(self):
        return {
            "platform": "codeforces",
            "problem_id": "2263C2",
            "problem_name": "Floor of MEX (Hard Version)",
            "problem_url": "https://codeforces.com/contest/2263/problem/C2",
            "submission_id": "390460609",
            "submission_url": "https://codeforces.com/contest/2263/submission/390460609",
            "epoch_second": 1789228037,
            "verdict": "AC",
            "language": "C++20 (GCC 13-64)",
            "time_ms": 62,
            "memory_bytes": 102400,
            "points": None,
            "rating": 1700,
            "tags": ["dp", "two pointers"],
            "time_limit_ms": None,
        }

    def test_luke_header_is_compact_and_managed(self):
        selected = self.sample_submission()
        rendered = header(selected, [selected, dict(selected)])
        self.assertTrue(rendered.startswith("/*\n" + LUKE_BANNER[0]))
        self.assertIn("CODEFORCES // 2263C2 // Floor of MEX (Hard Version)", rendered)
        self.assertIn("AC // C++20 (GCC 13-64) // 62 ms // 100.0 KiB", rendered)
        self.assertIn("2 attempts", rendered)
        self.assertIn(MARKER, rendered)
        self.assertNotIn("Generated on the annotated branch", rendered)
        self.assertNotIn("Match policy", rendered)

    def test_replacing_header_preserves_body_bytes(self):
        selected = self.sample_submission()
        body = b"\r\n#include <bits/stdc++.h>\r\nint main() {}\r\n\r\n"
        generated = header(selected, [selected]).encode("utf-8") + b"\n\n" + body
        self.assertEqual(without_header_bytes(generated), body)

        old = b"/* cp-code:submission-metadata\n * old header\n */\n\n" + body
        self.assertEqual(without_header_bytes(old), body)

    def test_uva_number_from_cpe_filename(self):
        self.assertEqual(uva_number(Path("cpe/2026-03-24/12063_Zeros_and_Ones.cpp")), "12063")
        self.assertIsNone(uva_number(Path("cpe/notes.cpp")))

    def test_uva_problem_only_header(self):
        rendered = header({
            "platform": "uva",
            "problem_id": "12063",
            "problem_name": "Zeros and Ones",
            "problem_url": "https://onlinejudge.org/external/120/12063.pdf",
            "time_limit_ms": 3000,
        })
        self.assertIn("UVa // 12063 // Zeros and Ones", rendered)
        self.assertIn("problem metadata: uHunt // time limit 3000 ms", rendered)
        self.assertNotIn("UNKNOWN", rendered)


if __name__ == "__main__":
    unittest.main()
